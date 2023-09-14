// Function:
    // Named function
    function add(a, b) {
        return a + b;
    }
    // Expression function
    let multiply = function(a, b) {
        return a * b;
    };
    // Arrow function
    let subtract = (a, b) => {
        return a - b;
    };

    alert("Hello World");
    let name = prompt("What is your name?"); // alert + input -> g.trị nhận = name
    console.log("Hello " + name);
    let num1 = parseInt("123");
    console.log(typeof num1); // Output: "number"
    let num2 = parseFloat("3.14");
    console.log(Math.round(num2)); // Output: 3
    let str = "javascript";
    console.log(str.toUpperCase()); // Output: "JAVASCRIPT"
    let fruits = ["apple", "banana", "orange"];
    fruits.sort();
    console.log(fruits);

// Array []
    fruits.push("mango");
    console.log(fruits.includes('peach'));   // false
    Array.prototype.myMap = function(callback) {  // tự tạo prototype myMap cho Array
        let newArray = [];
        for (let i = 0; i < this.length; i++) {
          newArray.push(callback(this[i], i, this));
        }
        return newArray;
        };
    Array.prototype.myFilter = function (cb) {
        var output = [];
        for (var i in this) {
            if (this.hasOwnProperty(i)) {
            var results = cb(this[i], i, this); //Xác định xem this[i] có được giữ lại hay không trong mảng output với điều kiện return khi gọi.
            if (results) {
                output.push(this[i]);
            }
            }
        }
        return output;
        };

// Object {key : value}
    let person = { 
        name: "John", 
        age: 30, 
        job: "developer" 
    };
    console.log(Object.keys(person)); // Output: ["name", "age", "job"]
    console.log(Object.values(person)); // Output: ["John", 30, "developer"]
    console.log(Object.entries(person)); // Output: [["name", "John"], ["age", 30], ["job", "developer"]]
    let newPerson = Object.assign(
        {}, 
        person, 
        { age: 35 }
        );
    console.log(newPerson); // Output: { name: "John", age: 35, job: "developer" }
    Object.freeze(person);
    person.age = 40;
    console.log(person.age); // Output: 30
    let json = JSON.stringify(person);
    console.log(json); // Output: "{\"name\":\"John\",\"age\":30,\"job\":\"developer\"}"
    let obj = JSON.parse(json);
    console.log(obj); // Output: { name: "John", age: 30, job: "developer" }

// DOM CSS
    // Lấy phần tử <p> với thuộc tính "id" là "myParagraph"
    var paragraph = document.getElementById("myParagraph");
    // Thay đổi màu chữ thành xanh
    paragraph.style.color = "blue";
    // Thay đổi nền thành màu vàng
    paragraph.style.backgroundColor = "yellow";
    
    // Thêm lớp "highlight"
    paragraph.classList.add("highlight");
    // Xóa lớp "highlight"
    paragraph.classList.remove("highlight");
    // Kiểm tra xem phần tử có chứa lớp "highlight" hay không
    if (paragraph.classList.contains("highlight")) {
        // Thực hiện một hành động nếu có lớp "highlight"    
    };

// JSON
    // Parsing JSON
    var json_data = '{"name": "John Doe", "age": 32, "isMarried": true, "hobbies": ["reading", "traveling", "swimming"]}';
    var data = JSON.parse(json_data);
    // Accessing data
    console.log("Name:", data.name);
    console.log("Age:", data.age);
    console.log("Is Married:", data.isMarried);
    console.log("Hobbies:", data.hobbies);
    // Creating JSON
    var data = {
        name: "Jane Doe",
        age: 28,
        isMarried: false,
        hobbies: ["painting", "singing", "dancing"]
    };
    var json_data = JSON.stringify(data);
    console.log("JSON Data:", json_data);

// Object constructor
    function Person(firstName, lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
    }
    var person1 = new Person("John", "Doe");
    var person2 = new Person("Jane", "Doe");

// Async 
    setTimeout(function() {
        console.log("done");
    }, 4000)
    console.log("done123");

// Callback hell
    getData(function(a) {
        getMoreData(a, function(b) {
            getMoreData(b, function(c) {
                getMoreData(c, function(d) {
                    console.log(d);
                });
            });
        });
    });
    //giải quyết "Callback Hell" bằng Promises:
    var promise = getData();
    promise
        .then(function(a) {
            return getMoreData(a);
        })
        .then(function(b) {
            return getMoreData(b);
        })
        .then(function(c) {
            return getMoreData(c);
        })
        .then(function(d) {
            console.log(d);
        });


//Promise (concept)
let promise = new Promise((resolve, reject) => { // executor
    let isSuccess = true;
    if (isSuccess) {
        setTimeout(() => {
            resolve("Thành công");
        }, 2000);
    } else {
            reject("Thất bại");
    }
});
  
    promise
        .then((message) => {
        console.log(message);
        })
        .catch((error) => {
        console.log(error);
        })
        .finally(() => {
          console.log("done");
        })

    //Promise.all
    var promise1 = new Promise(
        function (resolve) {
            setTimeout(function() {
                resolve([1]);
            }, 2000);
        }
    )
    var promise2 = new Promise(
        function (resolve) {
            setTimeout(function() {
                resolve([2, 3]);
            }, 5000);
        }
    )
    Promise.all([promise1, promise2])
        .then(function(result) {
            var result1 = result[0];
            var result2 = result[1];

            console.log(result1.concat(result2));
        });

// ES6
    //const
    const a = {
        name: "HIHI"
    }
    a.name = "HOHO";
    console.log(a.name);
    
    //class
    class Person {
        constructor(name, age) {
          this.name = name;
          this.age = age;
        }
        sayHello() {
          console.log(`Hello, my name is ${this.name} and I am ${this.age} years old.`);
        }
    }
      const person = new Person("John Doe", 30);
      person.sayHello();
      
    // default parameter value
    function logger(log, type = 'log') {
        console[type](log);
    }
    logger('Message0', 'warn');

    //Enhanced object literals
    var fieldName = 'name';
    var course = {
        [fieldName]: 'course',
        age, // age: age
        price, // price: price
        getAge() {
            return age;
        }
    };

    //Destructuring, Rest
    const numbers = [1, 2, 3, 4, 5];
    const [first, second, ...rest1] = numbers; // first = 1, second = 2, rest1 = [3, 4, 5]
    const [a, , c] = numbers; // -> a=1, c=2.
    
    var course = {
        name1: 'Javascript',
        price: 1000,
        image: 'img-address',
        description: 'abc',
        star: '10 stars',
        children: {
            name1: 'React',
        }
    };
    var {name1: parentName, star = '5 stars', children: {name1}, ...rest} = course;// phải ghi đúng key. rest = {image: 'img-address', description: 'abc'}
    // key children -> lấy đc object children
    // vì name1 của children trùng với course -> name1 = 'React'
    // có thể đổi tên key, dùng `:` -> sau khi đổi thì phải dùng key là key mới, nhưng object cũ ko bị thay đổi.
    // key stars ko tồn tại (underdefine) thì mặc định là '5 stars'

    function sum(...args) {
        return args.reduce((a, b) => a + b, 0);
    }      
    console.log(sum(1, 2, 3, 4, 5)); // 15
    // ...args để truyền nhiều tham số cho hàm sum
    // Tất cả các tham số được lưu trữ trong mảng args.

    function logger({name, price}) { //lấy thẳng key của object
        console.log(name);
        console.log(price);
    }
    logger({
        name: 'Js',
        price: 100,
        description: 'Javascript'
    })
      
    //Spread
    var arr1 = ['Js', 'Ruby', 'PHP'];
    var arr2 = ['ReactJS', 'Dart'];
    var arr3 = [...arr1, ...arr2]; //['Js', 'Ruby', 'PHP', 'ReactJS', 'Dart']

    //Tagged template literals
        // function highlight(...rest) {
        //     console.log(rest);
        // }
    function highlight([first, ...strings], ...values) {
        // first = "Hoc lap trinh " | strings= ["tai", "!"] | values= ["Js", "F8"]
        return values.reduce(
            (acc, curr) => [...acc, `<span>${curr}</span>`, strings.shift()],
            [first]
        )
        .join(''); 
    }
    var brand = 'F8';
    var course = 'Js';
    const html = highlight`Hoc lap trinh ${course} tai ${brand}!`;
        //Cách chạy:
        //Dùng function viết template string ` ` => truyền chữ và các biến nội suy ${} vào trong biến 
        // => rest nhận và biến thành mảng [] với 3 tham số đc truyền vào
        // [0]: là 1 array chứa các chuỗi ko có phần nội suy
                //  -> [0] : "Hoc lap trinh"
                //     [1] : "tai"
                //     [2] : "!"
        // [1] : biến nội suy đầu tiên -> cousre = "Js"
        // [2] = "F8"