import math

def euclidean_distance(point1, point2):
    return math.sqrt((point1[0] - point2[0])**2 + (point1[1] - point2[1])**2)

def closest_pair_rectangles(points):
    def closest_in_strip(strip, d):
        min_distance = d
        min_pair = None

        for i in range(len(strip)):
            for j in range(i+1, min(i+7, len(strip))):
                distance = euclidean_distance(strip[i], strip[j])
                if distance < min_distance:
                    min_distance = distance
                    min_pair = (strip[i], strip[j])

        return min_pair, min_distance

    def closest_pair_helper(points_x, points_y):
        if len(points_x) <= 3:
            return brute_force_closest_pair(points_x)

        mid = len(points_x) // 2
        mid_point = points_x[mid]

        left_x = points_x[:mid]
        right_x = points_x[mid:]

        left_y = []
        right_y = []

        for point in points_y:
            if point in left_x:
                left_y.append(point)
            else:
                right_y.append(point)

        left_pair, left_distance = closest_pair_helper(left_x, left_y)
        right_pair, right_distance = closest_pair_helper(right_x, right_y)

        d = min(left_distance, right_distance)

        strip = [point for point in points_y if abs(point[0] - mid_point[0]) < d]
        closest_in_strip_pair, closest_in_strip_distance = closest_in_strip(strip, d)

        if closest_in_strip_distance < d:
            return closest_in_strip_pair, closest_in_strip_distance

        if left_distance < right_distance:
            return left_pair, left_distance
        else:
            return right_pair, right_distance

    points_x = sorted(points, key=lambda x: x[0])
    points_y = sorted(points, key=lambda x: x[1])

    return closest_pair_helper(points_x, points_y)

def brute_force_closest_pair(points):
    min_distance = float('inf')
    closest_pair = None

    for i in range(len(points)):
        for j in range(i+1, len(points)):
            distance = euclidean_distance(points[i], points[j])
            if distance < min_distance:
                min_distance = distance
                closest_pair = (points[i], points[j])

    return closest_pair, min_distance

# Example usage:
points = [(2,3), (12,30), (40,50), (5,1), (12,10), (3,4)]
closest_pair, min_distance = closest_pair_rectangles(points)
print("Closest pair:", closest_pair)
print("Distance:", min_distance)
