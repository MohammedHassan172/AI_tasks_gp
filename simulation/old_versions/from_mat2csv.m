load('train_data.mat');
data_mat = train_data.data(2:length(train_data.time),:);
writematrix(lables,'Training_data.csv','WriteMode','append');
writematrix(data_mat,'Training_data.csv','WriteMode','append');