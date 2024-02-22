/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Bai2;
/**
 *
 * @author ASUS
 */
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;
public class Calculator {
   public List<String> infixToPostfix(String s){
        List<String>list=new ArrayList<>();
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            if(Character.isDigit(c)){
                StringBuilder numbers=new StringBuilder();
                while(i<s.length()&&Character.isDigit(s.charAt(i))){
                    numbers.append(String.valueOf(s.charAt(i)));
                    i++;
                }
                list.add(numbers.toString());
                i--;
            }else{
                list.add(String.valueOf(c));
            }
        }
        Map<String,Integer>precedence =new HashMap<>();
        precedence.put("+", 1);
        precedence.put("-", 1);
        precedence.put("*", 2);
        precedence.put("/", 2);
        List<String> result=new ArrayList<>();
        Stack<String>stack=new Stack<>();
        int i=0;
        while(i<list.size()){
            String c=list.get(i);
            if(isOperator(c)){
                if(stack.isEmpty()){
                    stack.push(c);
                    i++;
                }else{
                        if(stack.peek().equals("(")){
                            stack.push(c);
                            i++;
                        }else if(isOperator(stack.peek())&&precedence.get(c)>precedence.get(stack.peek())){
                            stack.push(c);
                            i++;
                        }
                        else if(isOperator(stack.peek())&&precedence.get(c)<=precedence.get(stack.peek())){
                            result.add(stack.peek());
                            stack.pop();
                        }
                }
            }
            else if(c.equals("(")){
                stack.push(c);
                i++;
            }else if(c.equals(")")){
                if(!stack.isEmpty()){
                    if(stack.peek().equals("(")){
                        stack.pop();
                        i++;
                    }else{
                        result.add(stack.peek());
                        stack.pop();
                    }
                }
            }else{
                result.add(c);
                i++;
            }
        }
        while(!stack.isEmpty()){
            result.add(stack.peek());
            stack.pop();
        }
        return result;
    }

    public boolean isOperator(String c) {
        return  c.equals("+")|| c.equals("-")|| c.equals("*")|| c.equals("/");
    }
    public Double caculatePostfix(String s){
        List<String>list=infixToPostfix(s);
        Stack<Double>stack=new Stack<>();
        for(int i=0;i<list.size();i++){
            String c=list.get(i);
           if(isOperator(c)){
                double b=stack.peek();
               stack.pop();
                double a=stack.peek();
               stack.pop();
               if(c.equals("-")) a-=b;
               else if(c.equals("+"))a+=b;
               else if(c.equals("*"))a*=b;
               else if(c.equals("/")){
                   if(b==0) throw new ArithmeticException("Division by zero");
                   else{
                    a/=b;
                   }
               }
               stack.push(a);
            }else{
               try{
                   stack.push(Double.parseDouble(c));
               }catch (NumberFormatException e){
                   System.out.println(e.getMessage());
               }
           }
        }
        if(stack.size()==1){
            return stack.peek();
        }else{
            System.out.println("Lỗi");
            return null;
        }
    }

    public static void main(String[] args) {
        String s="5+13-(12-4*6)-((3+4)-5)";
        Calculator calculate = new Calculator();
        List<String> result = calculate.infixToPostfix(s);
        for (String string : result) {
            System.out.println("bai2.InfixCalculate.main()" + string);
        }
    }
}
