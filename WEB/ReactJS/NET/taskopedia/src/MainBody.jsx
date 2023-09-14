import Student from "./component/Student/Student";
import StudentReview from "./component/Student/StudentReview";
// -> component

// function MainBody() {
// hoặc dùng arrow function
const MainBody = () => {
  const course = "React JS";
  const count = 117;
  const manager = "Phung Anh";

  return (
    <div style={{ minHeight: "60vh" }}>
      <p>
        In this course we will learn {course} <br />
        Total lecture - {count}
      </p>
      <ul>
        <li>Call {manager}</li>
        <li>Go to walmart</li>
      </ul>
      <div>
        Phone:{" "}
        <input maxLength={5} readOnly={false} placeholder="Input phone"></input>
      </div>
      <div className="container row pt-5">Students Enrolled</div>
      <Student
        exp={2}
        name="Joann"
        // headshot="https://api.lorem.space/image/face?w=150&h=150"
      >
        <StudentReview />
      </Student>
      <Student
        exp={6}
        name="Marcella"
        // headshot="https://api.lorem.space/image/face?w=150&h=151"
      >
        <StudentReview />
      </Student>
      <Student
        exp={4}
        name="Beer"
        // headshot="https://api.lorem.space/image/face?w=150&h=152"
      >
        <StudentReview />
      </Student>
    </div>
  );
};

export default MainBody;
