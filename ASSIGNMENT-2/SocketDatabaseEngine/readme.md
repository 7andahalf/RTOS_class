# DatabaseEngine

Similar to socket echo engine. The file is transferred in packets. The program was tested so that it can transfer different files and also give an error message when file is not found.

# Performance

Performance data was collected for each of the tasks and the time difference between a request and reply was measured. All the tasks were run for a considerable time so that the average value will be as accurate as possible. Experiments were conducted when multiple clients (1 to 5) are requesting the same server.

Following table depicts the time taken to perform a task on an average by every task in microseconds. Server column is the time taken by server to service one client. Then individual columns are time taken to get the query serviced. All time units are in micro seconds.

| # Clients | Server  | ClientA | ClientB | ClientC | ClientD | ClientE |
|-----------|---------|---------|---------|---------|---------|---------|
| 1         | 197  | 39802  |         |         |         |         |
| 2         | 211  | 40255  | 40484 |         |         |         |
| 3         | 198  | 39849  | 39885 | 39825 |         |         |
| 4         |  216 | 40876 | 40838 | 40872 | 41028 |         |
| 5         | 218  | 39341| 39392 | 39390 | 39304 | 39457 |

We can see that, in this case the file size also matters. Hence some clients may take longer time and some may take shorter time, So each client was made to request the same file. In case of three clients, server takes about 200uS to service one file. Even though the data was collected over a long time, it is possible that due to scheduling and other tasks in a general purpose OS, we can see vast variation in server service times.