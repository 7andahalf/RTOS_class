# DatabaseEngine

Similar to echo engine. The file is transferred in packets.

# Performance

Performance data was collected for each of the tasks and the time difference between a request and reply was measured. All the tasks were run for a considerable time so that the average value will be as accurate as possible. Experiments were conducted when multiple clients (1 to 5) are requesting the same server.

Following table depicts the time taken to perform a task on an average by every task in microseconds. Server column is the time taken by server to service one client. Then individual columns are time taken to get the query serviced. All time units are in micro seconds.

| # Clients | Server  | ClientA | ClientB | ClientC | ClientD | ClientE |
|-----------|---------|---------|---------|---------|---------|---------|
| 1         | 81.13   | 148.03  |         |         |         |         |
| 2         | 557.08  | 117.76  | 1104.12 |         |         |         |
| 3         | 482.53  | 1489.8  | 1318.68 | 1467.81 |         |         |
| 4         |  413.95 | 1625.22 | 1623.67 | 1621.11 | 1410.83 |         |
| 5         | 383.99  | 1808.14 | 1801.51 | 1621.99 | 1796.88 | 1793.05 |

We can see that, in this case the file size also matters. Hence some clients may take longer time and some may take shorter time, So each client was made to request the same file. In case of three clients, server takes about 500uS to service one file. Hence, each client would get a chance after 1.5mS as shown in the experimental data. Even though the data was collected over a long time, it is possible that due to scheduling and other tasks in a general purpose OS, we can see vast variation in server service times.