unbatched_data = load('phase_3_data\input_data.mat');
batch_size = 100;
batches_num = 20;
input_W = cell(1,batches_num);
input_T = cell(1,batches_num);
for i = batch_size:batch_size:length(unbatched_data.input_data.Time)
       
       time = unbatched_data.input_data.time((i- batch_size + 1):i);
       time = time - (((i/batch_size) - 1) * batch_size * 2);
       input_W{i/batch_size} = unbatched_data.input_data.Data((i- batch_size + 1):i,1);
       input_T{i/batch_size} = unbatched_data.input_data.Data((i- batch_size + 1):i,2);
       
       input_W{i/batch_size} = [time , input_W{i/batch_size}];
       input_T{i/batch_size} = [time , input_T{i/batch_size}];

    
end
save("input_W&T_batches.mat","input_T","input_W");

% for i = 1:20
%     if input_T{i}(100,1) == 198
%         disp(i + " yes");
%     else
%         disp(i + " no");
%     end
% end
% input_W_2 = input_W(841:2001,:)