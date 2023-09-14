import logo from "../images/react.png";

const subHeaderStyle = {
  color: "blue",
  backgroundColor: "lightgray",
};

function MainHeader() {
  return (
    <div className="pt-3 pl-2" style={{backgroundColor: "black"}}>
      <img src={logo} style={{ height: "30px" }} className="align-top" alt=""/>
      <span className="h2 pt-4 text-white-50">REACT COURSE</span>
    </div>
  );
}
function SubHeader() {
  return (
    <p style={subHeaderStyle} className="text-center">
      In this course, we will learn react js building React
    </p>
  );
}
const Header = () => {
  return (
    <div>
      <MainHeader />
      <SubHeader></SubHeader>
    </div>
  );
}

export default Header;
