import React from "react";
import {Line} from 'react-chartjs-2';


const getData = (monthlyOrders) => {
    return {
    labels: ['January', 'February', 'March', 'April', 'May', 'June',
             'July', 'August', 'September', 'October', 'November', 'December'],
    datasets: [
        {
            label: 'Number Of Orders',
            fill: false,
            lineTension: 0.2,
            backgroundColor: '#fc3a5b',
            borderColor: 'rgb(44,84,132)',
            borderJoinStyle: 'miter',
            pointBackgroundColor: '#fc3a5b',
            pointHoverBackgroundColor: '#fc3a5b',
            data: monthlyOrders
        }
    ]
}};


const Chart = ({monthlyOrders}) => {
    return (

        <div className='chart'>
            <Line data={getData(monthlyOrders)} />
        </div>
    );
};

export default Chart;