# EchoEngine

A single message queue is used for exchange of data. Every message is addressed to a particular task and the return address is also given. The program was tested by giving different testcases like a, A, $ which returned A, a, $ as expected.

# Performance

Performance data was collected for each of the tasks and the time difference between a request and reply was measured. All the tasks were run for a considerable time so that the average value will be as accurate as possible. Experiments were conducted when multiple clients (1 to 5) are requesting the same server.

Following table depicts the time taken to perform a task on an average by every task in microseconds. Server column is the time taken by server to service one client. Then individual columns are time taken to get the query serviced. All time units are in micro seconds.

| # Clients | Server | ClientA | ClientB | ClientC | ClientD | ClientE |
|-----------|--------|---------|---------|---------|---------|---------|
| 1         | 4.39   | 6.61    |         |         |         |         |
| 2         | 6.94   | 14.94   | 15.16   |         |         |         |
| 3         |  7.02  | 23.48   | 23.44   | 22.43   |         |         |
| 4         | 7.25   | 32.54   | 32.59   | 32.07   | 30.3    |         |
| 5         | 7.19   | 40.60   | 40.65   | 40.44   | 39.81   | 37.95   |

We can see that, if a single task is running then the server will take around 4.4 uS to service one querry. If more than one clients are running it takes around 7 uS. Hence if three clients are running every client will get a chance after 7*3 = 21 ~= 23 uS. Which is being shown in the results obtained experimentally. Even though the data was collected over a long time, it is possible that due to scheduling and other tasks in a general purpose OS, we can see some variation in server service times.