/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bai2;
/**
 *
 * @author ASUS
 */
import java.util.Stack;
public class Test {
    public String calculate(String input) {
        Stack<Double> nums = new Stack<>(); // stack lưu trữ các số trong biểu thức
        Stack<Character> ops = new Stack<>(); // stack lưu trữ các toán tử trong biểu thức

        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (Character.isDigit(c)) { // nếu là số
                boolean isDouble = false;
                StringBuilder _number = new StringBuilder();
                while (i < input.length() && (Character.isDigit(input.charAt(i))
                        || input.charAt(i) == '.')) {
                    if (input.charAt(i) == '.') {
                        if (!isDouble) {
                            isDouble = true;
                        } else {
                            throw new IllegalArgumentException("");
                        }
                    }
                    _number.append(input.charAt(i));
                    i++;
                }
                i--;
                nums.push(Double.valueOf(_number.toString())); // thêm số vào stack
            } else if (c == '+' || c == '-' || c == '*' || c == '/') { // nếu là toán tử
                while (!ops.empty() && precedence(ops.peek()) >= precedence(c)) {
                    double val2 = nums.pop();
                    double val1 = nums.pop();
                    char op = ops.pop();
                    double res = eval(val1, val2, op);
                    nums.push(res); // tính toán và đưa kết quả vào stack
                }
                ops.push(c); // thêm toán tử vào stack
            }
        }

        while (!ops.empty()) {
            double val2 = nums.pop();
            double val1 = nums.pop();
            char op = ops.pop();
            double res = eval(val1, val2, op);
            nums.push(res); // tính toán và đưa kết quả vào stack
        }

        return String.valueOf(nums.pop()); // in ra kết quả cuối cùng
    }

    // định nghĩa độ ưu tiên của toán tử
    public static int precedence(char op) {
        if (op == '+' || op == '-') {
            return 1;
        }
        if (op == '*' || op == '/') {
            return 2;
        }
        return 0;
    }

    // tính toán kết quả của biểu thức
    public static double eval(double val1, double val2, char op) {
        if (op == '+') {
            return val1 + val2;
        }
        if (op == '-') {
            return val1 - val2;
        }
        if (op == '*') {
            return val1 * val2;
        }
        if (op == '/') {
            return val1 / val2;
        }
        return 0;
    }
    public static void main(String[] args) {
        Test test = new Test();
       
        System.out.println(test.calculate("1.2+1"));
    }
}
