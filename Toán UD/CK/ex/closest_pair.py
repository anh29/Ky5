import math

# Hàm tính khoảng cách giữa hai điểm
def distance(p1, p2):
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

# Hàm tìm khoảng cách tối thiểu giữa các điểm trong một tập hợp đã sắp xếp theo x
def closest_pair(points):
    n = len(points)

    # Trường hợp cơ bản: Nếu tập hợp có ít hơn hoặc bằng 3 điểm, thì tìm khoảng cách tối thiểu bằng cách kiểm tra từng cặp điểm
    if n <= 3:
        min_dist = float('inf')
        for i in range(n):
            for j in range(i + 1, n):
                dist = distance(points[i], points[j])
                min_dist = min(min_dist, dist)
        return min_dist

    # Chia tập hợp thành hai phần
    mid = n // 2
    left_half = points[:mid]
    right_half = points[mid:]

    # Đệ quy tìm khoảng cách tối thiểu ở cả hai phần
    left_min = closest_pair(left_half)
    right_min = closest_pair(right_half)

    # Tìm khoảng cách tối thiểu trên đường biên
    min_dist = min(left_min, right_min)

    # Xác định các điểm trên đường biên
    boundary_points = [point for point in points if abs(point[0] - points[mid][0]) < min_dist]

    # Sắp xếp các điểm trên đường biên theo y
    boundary_points.sort(key=lambda x: x[1])

    # Kiểm tra khoảng cách tối thiểu trên đường biên
    for i in range(len(boundary_points)):
        for j in range(i + 1, len(boundary_points)):
            if boundary_points[j][1] - boundary_points[i][1] < min_dist:
                dist = distance(boundary_points[i], boundary_points[j])
                min_dist = min(min_dist, dist)

    return min_dist

# Hàm chính để tìm khoảng cách tối thiểu
def find_closest_pair(points):
    # Sắp xếp tập hợp điểm theo tọa độ x
    points.sort(key=lambda x: x[0])
    return closest_pair(points)

# Example usage:
points = [(3, 1), (6, 1), (7, 6), (7, 13), (3, 10), (2, 9), (1, 3)]
min_distance = find_closest_pair(points)
print("Khoảng cách tối thiểu giữa các cặp điểm:", min_distance)