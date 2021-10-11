import numpy as np
import datetime
start = datetime.datetime(2000, 1, 1)
dt_array = np.array([start + datetime.timedelta(hours=i) for i in range(24)])
print(dt_array)
