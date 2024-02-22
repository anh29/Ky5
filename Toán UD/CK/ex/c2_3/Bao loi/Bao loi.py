import matplotlib.pyplot as plt

# Lớp điểm với thuộc tính x, y là tọa độ
class Point: 
    def __init__(self, x, y): 
        self.x = x 
        self.y = y 
        
def add_points(arr_points):
    points = [Point(row[0], row[1]) for row in arr_points]
    return points
    

# Hàm tìm điểm bên trái nhất 
def left_index(points): 
    minn = 0
    for i in range(1,len(points)): 
        if points[i].x < points[minn].x: 
            minn = i 
        elif points[i].x == points[minn].x: 
            if points[i].y > points[minn].y: 
                minn = i 
    return minn 
  
# Hàm xác định hướng xoay của 3 điểm
def orientation(p, q, r): 
    # Để xác định hướng của bộ ba điểm (p, q, r).  
    # Hàm trả về các giá trị sau  
    # 0 --> p, q và r thẳng hàng  
    # 1 --> Theo chiều kim đồng hồ  
    # 2 --> Ngược chiều kim đồng hồ 
    val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y)
    if val == 0: 
        return 0
    elif val > 0: 
        return 1
    else: 
        return 2
  
# Thuật toán tìm bao lồi
def convex_hull(points, n): 
    # Phải có ít nhất 3 điểm  
    if n < 3: 
        return

    # Tìm điểm bên trái nhất 
    l = left_index(points) 
  
    hull = []   
    
    # Bắt đầu từ điểm bên trái nhất, tiếp tục di chuyển ngược chiều kim đồng hồ  
    # cho đến khi quay lại điểm bắt đầu. Vòng lặp này chạy O(h)  
    # lần với h là số điểm trong kết quả hoặc output.  
    
    p = l 
    q = 0
    while(True): 
        # Thêm điểm hiện tại vào kết quả  
        hull.append(p) 
        
        # Tìm kiếm điểm 'q' sao cho orientation(p, q, x) ngược chiều kim đồng hồ  
        # với tất cả các điểm 'x'. Ý tưởng  
        # là theo dõi điểm gần nhất được ghé qua theo ngược chiều kim đồng hồ trong q. 
        # Nếu bất kỳ điểm 'i' nào ngược chiều kim đồng hồ hơn q, thì cập nhật q.  
        
        q = (p + 1) % n 
        for i in range(n): 
            # Nếu i ngược chiều kim đồng hồ hơn q hiện tại  
            # thì cập nhật q  
            if(orientation(points[p],  
                           points[i], points[q]) == 2): 
                q = i 
        
        # Bây giờ q là điểm gần nhất được ghé qua theo ngược chiều kim đồng hồ với p  
        # Gán p là q cho vòng lặp tiếp theo, để q được thêm vào  
        # kết quả 'hull'  
        
        p = q 

        # Trong khi chưa quay lại điểm đầu tiên 
        if(p == l): 
            break

    return hull
  
input = [[9, 8], [5, 8], [7, 5], [8, 1], [1, 7], [2, 6], [3, 2]]
points = add_points(input)

# Tạo hàm vẽ lại bao lồi
def plot_convex_hull(points, convex_hull):
    points_x = [point.x for point in points]
    points_y = [point.y for point in points]

    hull_x = [points[i].x for i in convex_hull]
    hull_y = [points[i].y for i in convex_hull]
    
    plt.grid(True)
    plt.plot(points_x, points_y, 'o')
    plt.fill(hull_x + [hull_x[0]], hull_y + [hull_y[0]], color='blue', alpha=0.2)
    plt.plot(hull_x + [hull_x[0]], hull_y + [hull_y[0]], 'r-', )
    plt.show()

# Tìm bao lồi và vẽ kết quả
convex_hull = convex_hull(points, len(points)) 

print("\nCác điểm trên bao:")
for each in convex_hull: 
    print(points[each].x, points[each].y)

plot_convex_hull(points, convex_hull)
