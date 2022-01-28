import "./styles/App.scss";
import { BrowserRouter as Router, Switch, Route } from "react-router-dom";
import Home from "./Pages/Home";
import Sidebar from "./components/Sidebar";
import About from "./Pages/About";
import Skills from "./Pages/Skills";
import Contact from "./Pages/Contact";

function App() {
  return (
    <Router>
      <div className="app">
      <Sidebar />
        <Switch>
        <Route path="/contact">
            <Contact/>
          </Route>
        <Route path="/skills">          
            <Skills />
          </Route>

          <Route path="/about">        
            <About />
          </Route>
          <Route path="/">
            <Home />
          </Route>
        </Switch>
      </div>
    </Router>
  );
}

export default App;
