import React from "react";
import {BrowserRouter as Router, Switch, Route} from 'react-router-dom';

import {classesSize, annualWages} from "./fakeData";
import './styles/main.css'

//My Components
import NavBar from "./Components/NavBar/NavBar";
import Custom from "./routing/Custom";
import About from "./routing/About";
import Footer from "./Components/Footer/Footer";


const App = () => {
    return (
        <>
            <Router>
                <div className='App'>
                    <NavBar/>
                    <Switch>
                        <Route path='/' exact={true} component={About}/>
                        <Route path='/custom' component={() => <Custom classSizes={classesSize}
                                                                       annualWages={annualWages}/>}
                        />
                    </Switch>
                </div>
            </Router>
            <Footer/>
        </>
    );
};

export default App;
