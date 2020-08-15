import React from 'react';
import './styles/main.css'

import NumberDisplay from "./components/NumberDisplay/NumberDisplay"; // "build in" assignment components
import withClickCount from "./components/Task1/withClickCount"; // Task 1
import Task2 from "./components/Task2/Task2";
import Task3 from "./components/Task3/Task3";
import Task4 from "./components/Task4/Task4";

import Header from "./components/Header/Header";

function App() {
    const ClickCountDisplay = withClickCount(NumberDisplay); //also possible to export withClickCount(NumberDisplay) in NumberDisplay.js

    return (
        <div className="App">
            <Header/>

            <div className='tasks-container'>
                <div className='task'>
                    <h2>HOC</h2>
                    <ClickCountDisplay/>
                </div>

                <div className='task'>
                    <h2>Class Component</h2>
                    <Task2 number={0}/>
                </div>

                <div className='task'>

                    <h2>Custom Hook</h2>
                    <Task3/>
                </div>

                <div className='task'>

                    <h2>Component as prop</h2>
                    <Task4 Component={NumberDisplay}/>
                </div>
            </div>

            <footer>Made By Adi | 2020</footer>
        </div>
    );
}

export default App;
