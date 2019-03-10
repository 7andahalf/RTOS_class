# EchoEngine

A socket is used for exchange of data. The program was tested by giving different testcases like a, A, $ which returned A, a, $ as expected.

# Performance

Performance data was collected for each of the tasks and the time difference between a request and reply was measured. All the tasks were run for a considerable time so that the average value will be as accurate as possible. Experiments were conducted when multiple clients (1 to 5) are requesting the same server.

Following table depicts the time taken to perform a task on an average by every task in microseconds. Server column is the time taken by server to service one client. Then individual columns are time taken to get the query serviced. All time units are in micro seconds.

| # Clients | Server | ClientA | ClientB | ClientC | ClientD | ClientE |
|-----------|--------|---------|---------|---------|---------|---------|
| 1         | 4.75   | 15.58    |         |         |         |         |
| 2         | 4.65   | 34.82   | 34.98   |         |         |         |
| 3         | 4.79  | 56.97   | 57.3   | 56.8   |         |         |
| 4         | 4.87   | 76.97   | 77.11   | 76.79  | 77.5    |         |
| 5         | 4.88   | 97.47   | 98.07   | 97.51   | 96.21  | 97.53   |

We can see that, if a single task is running then the server will take around 5 uS to service one querry. We can see a steady increase in time taken to service each request as the number of tasks increase. Even though the data was collected over a long time, it is possible that due to scheduling and other tasks in a general purpose OS, we can see some variation in server service times.