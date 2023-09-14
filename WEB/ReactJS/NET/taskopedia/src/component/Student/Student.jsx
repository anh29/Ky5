import { faker } from "@faker-js/faker";
import React from "react";

// Function component
//function Student(props) {
//  Arrow function
// const Student = (props) => {
//   return (
//     <div className="col-6 p-4">
//       <div className="row border">
//         <div className="col-2">
//           <img
//             alt=""
//             src={faker.image.avatar()}
//             // src={props.headshot}
//             className="w-100 py-2"
//           />
//         </div>
//         <div className="col-8">
//           {props.name}
//           <br />
//           Programming experience {props.exp} years
//         </div>
//         <div className="col-2 align-self-center">{props.children}</div>
//       </div>
//     </div>
//   );
// };

// Class component
class Student extends React.Component {
  render() {
    return (
      <div className="col-6 p-4">
        <div className="row border">
          <div className="col-2">
            <img
              alt=""
              src={faker.image.avatar()}
              // src={props.headshot}
              className="w-100 py-2"
            />
          </div>
          <div className="col-8">
            {this.props.name}
            <br />
            Programming experience {this.props.exp} years
          </div>
          <div className="col-2 align-self-center">{this.props.children}</div>
        </div>
      </div>
    );
  }
}
export default Student;
