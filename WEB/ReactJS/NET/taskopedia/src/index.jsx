import ReactDOM from "react-dom/client";
import "./css/style.css";

import MainHeader from "./layout/Header";
import Footer from "./layout/Footer";
import MainBody from "./MainBody";
const root = ReactDOM.createRoot(document.getElementById("root"));


// root.render(MainBody()) // approach wrong
// root.render(<MainBody/>) // right. Add HTML tag = MainBody (*Chu Dau Ph Viet Hoa)
root.render(
  <div style={{minHeight: "70vh"}}>
    <MainHeader />
    <div className="px-4">
    <MainBody /> {/* easy reuse */}
    </div>
    <Footer />
  </div>
);
