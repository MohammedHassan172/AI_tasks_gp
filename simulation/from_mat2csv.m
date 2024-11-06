load('phase_3_data\input_W&T_batches.mat');
% writematrix(lables,'Training_data.csv');
% 9 bacthes done.
for i = 10:20
    load('phase_3_data\input_W&T_batches.mat');
    sim_time = 200;
    input_t = input_T{i};
    input_w = input_W{i};
    time = 1:sim_time;
    time = time.';
    time = [time,time];
    sim('graduation_project_prototype_collect_4.slx',sim_time);
    load('train_data.mat');
    load('out_speed.mat');
    data_mat = train_data.data(2:length(train_data.time),:);
    speed_mat = out_speed.data(2:length(out_speed.time),:);
    writematrix(data_mat,'Training_data.csv','WriteMode','append');
    % writematrix(data_mat,'Training_data_2.csv','WriteMode','append');
    writematrix(speed_mat,'out_speed_data.csv','WriteMode','append');
    disp("batch:  "+ i);
    clear
    Simulink.sdi.clear
end



% % input_T = input_T_2;
% % input_W = input_W_2;
% % sim('graduation_project_prototype_collect_4_0',1000);
% load('train_data.mat');
% load('out_speed.mat');
% data_mat = train_data.data(2:length(train_data.time),:);
% speed_mat = out_speed.data(2:length(out_speed.time),:);
% %writematrix(lables,'Training_data.csv','WriteMode','append');
% writematrix(data_mat,'Training_data.csv','WriteMode','append');
% writematrix(data_mat,'Training_data_2.csv','WriteMode','append');
% writematrix(speed_mat,'out_speed_data.csv','WriteMode','append');
% clear
% disp("1");

% load('input_W&T_batches.mat');
% input_T = input_T_3;
% input_W = input_W_3;
% sim('graduation_project_prototype_collect_4_0',1000);
% load('train_data.mat');
% load('out_speed.mat');
% data_mat = train_data.data(2:length(train_data.time),:);
% speed_mat = out_speed.data(2:length(out_speed.time),:);
% %writematrix(lables,'Training_data.csv','WriteMode','append');
% writematrix(data_mat,'Training_data.csv','WriteMode','append');
% writematrix(data_mat,'Training_data_3.csv','WriteMode','append');
% writematrix(speed_mat,'out_speed_data.csv','WriteMode','append');
% clear
% disp("2");

% load('input_W&T_batches.mat');
% input_T = input_T_4;
% input_W = input_W_4;
% sim('graduation_project_prototype_collect_4_0',322);
% load('train_data.mat');
% load('out_speed.mat');
% data_mat = train_data.data(2:length(train_data.time),:);
% speed_mat = out_speed.data(2:length(out_speed.time),:);
% %writematrix(lables,'Training_data.csv','WriteMode','append');
% writematrix(data_mat,'Training_data.csv','WriteMode','append');
% writematrix(data_mat,'Training_data_4.csv','WriteMode','append');
% writematrix(speed_mat,'out_speed_data.csv','WriteMode','append');
% clear
% disp("3");