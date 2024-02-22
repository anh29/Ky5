import math

def orientation(p, q, r):
    # Hàm xác định hướng của ba điểm p, q, r.
    # Trả về:
    # 0 nếu p, q, r thẳng hàng (colinear)
    # 1 nếu p, q, r theo chiều kim đồng hồ (clockwise)
    # -1 nếu p, q, r ngược chiều kim đồng hồ (counterclockwise)
    val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
    if val == 0:
        return 0
    return 1 if val > 0 else -1

def convex_hull(points):
    n = len(points)
    
    # Trường hợp đặc biệt: Nếu có ít hơn 3 điểm, thì chúng không thể tạo thành bao lồi.
    if n < 3:
        return None
    
    # Tìm điểm bắt đầu (có tọa độ y nhỏ nhất), sắp xếp các điểm theo góc tạo bởi đường ngang và đường từ điểm bắt đầu đến các điểm còn lại.
    start = min(points, key=lambda point: (point[1], point[0]))
    sorted_points = sorted(points, key=lambda point: (math.atan2(point[1]-start[1], point[0]-start[0]), point))
    
    hull = [start, sorted_points[0]]
    
    for i in range(1, n):
        while len(hull) > 1 and orientation(hull[-2], hull[-1], sorted_points[i]) != -1:
            hull.pop()
        hull.append(sorted_points[i])
    
    return hull

def convex_hull_area(hull):
    # Tính diện tích của bao lồi bằng cách sử dụng công thức Green:
    # Area = 1/2 * |sum(xi * yi+1 - xi+1 * yi)| for i in range(n-1)
    area = 0
    n = len(hull)
    for i in range(n - 1):
        area += hull[i][0] * hull[i + 1][1] - hull[i + 1][0] * hull[i][1]
    area += hull[-1][0] * hull[0][1] - hull[0][0] * hull[-1][1]
    area = abs(area) / 2.0
    return area


# Example usage:
points = []

# n = int(input())
# for i in range(n):
#     x,y = list(map(int, input().split()))
#     points.append((x,y))

points = [(1, 3), (3,1), (5,3), (6,5), (7,6), (3,2), (2,5), (2,9), (4,7), (6,3), (7,9), (6,1), (3,10), (5,9), (7,13)]
result = convex_hull(points)
print("Bao lồi:", result)

if result:
    area = convex_hull_area(result)
    print("Diện tích bao lồi:", area)
