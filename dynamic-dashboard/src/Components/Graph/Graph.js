import React from "react";
import CanvasJSReact from '../../canvasJS/canvasjs.react';
import {Rnd} from "react-rnd";

const {CanvasJSChart, CanvasJS} = CanvasJSReact;

const Graph = ({fakeData, type, isDynamic, title}) => {
    const dataPoints = [];

    fakeData.forEach(country => {
        const {name, averageClassSize, averageAnnualWages} = country;
        const y = averageClassSize ? averageClassSize : averageAnnualWages;
        const newDataPoint = {
            label: name,
            y: y
        }
        dataPoints.push(newDataPoint);
    })

    CanvasJS.addColorSet("setColors",
        [//colorSet Array
            "#2c3ac5",
            "#7545d8",
            "#fc74ff",
            "#ff952e",
            "#f4c733"
        ]);

    const options = {
        colorSet: "setColors",
        exportEnabled: true,
        theme: "light1", // "light1", "dark1", "dark2"
        title: {
            text: title,
            fontSize: 40,
        },
        data: [{
            type: type,
            indexLabel: "{label}: {y}",
            startAngle: -90,
            dataPoints: dataPoints,
        }]
    }

    const component = (
        <div>
            <CanvasJSChart options={options}/>
        </div>
    );

    if (isDynamic) {
        return <Rnd default={{x: 400, y: 200}}> {component} </Rnd>
    }

    return (<div className='chart-not-dynamic'>{component}</div>);

}

export default Graph;