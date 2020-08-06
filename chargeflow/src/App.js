import React from 'react';
import Menu from './Components/Menu/Menu';
import Dashboard from './Components/Dashboard/Dashboard';

import './style/main.css'

import './App.css';

function App() {
  return (
    <div className="App">
        <Menu/>
        <Dashboard/>
    </div>
  );
}

export default App;
