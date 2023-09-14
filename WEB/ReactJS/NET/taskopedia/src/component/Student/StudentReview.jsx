import React from "react";
// Function component:
//function StudentReview() {
// Class component
class StudentReview extends React.Component {
  render() {
    return (
      <div className="row">
        <i
          class="bi bi-hand-thumbs-up-fill text-success col-1"
          style={{ cursor: "pointer" }}
        ></i>
        <i
          class="bi bi-hand-thumbs-down-fill text-danger col-1"
          style={{ cursor: "pointer" }}
        ></i>
      </div>
    );
  }
}
export default StudentReview;
