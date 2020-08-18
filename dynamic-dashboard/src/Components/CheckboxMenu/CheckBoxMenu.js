import React from "react";

import Flag from "../Flag/Flag";
import CheckBox from "./CheckBox";
import Graph from "../Graph/Graph";
import MyTable from "../Table/Table";

const CheckBoxMenu = ({classSizes, annualWages}) => {

    const classSizeTitle = 'Average Class Size';
    const annualWagesTitle = 'Average Annual Wages (USD)';

    const averageClassSize = [
        {
            label: 'Column',
            componentToRender: <Graph fakeData={classSizes} type='column' isDynamic={true} title={classSizeTitle}/>
        },
        {
            label: 'Pie',
            componentToRender: <Graph fakeData={classSizes} type='pie' isDynamic={true} title={classSizeTitle}/>
        },
        {
            label: 'Line',
            componentToRender: <Graph fakeData={classSizes} type='line' isDynamic={true} title={classSizeTitle}/>
        },
        {
            label: 'Doughnut',
            componentToRender: <Graph fakeData={classSizes} type='doughnut' isDynamic={true} title={classSizeTitle}/>
        },
        {
            label: 'Table',
            componentToRender: <MyTable fakeData={classSizes} title={classSizeTitle}/>
        },

    ];
    const maxMinClasses = [  //assuming data is sorted : most crowded --> least crowded
        {
            label: 'Most',
            componentToRender:
                <Flag title='Most Crowded Classes'
                      country={classSizes[0]}
                />
        },
        {
            label: 'Least',
            componentToRender:
                <Flag title='Least Crowded Classes'
                      country={classSizes[classSizes.length - 1]}
                />
        }
    ]

    const averageAnnualWages = [
        {
            label: 'Column',
            componentToRender: <Graph fakeData={annualWages} type='column' isDynamic={true} title={annualWagesTitle}/>
        },
        {
            label: 'Pie',
            componentToRender: <Graph fakeData={annualWages} type='pie' isDynamic={true} title={annualWagesTitle}/>
        },
        {
            label: 'Line',
            componentToRender: <Graph fakeData={annualWages} type='line' isDynamic={true} title={annualWagesTitle}/>
        },
        {
            label: 'Doughnut',
            componentToRender: <Graph fakeData={annualWages} type='doughnut' isDynamic={true} title={annualWagesTitle}/>
        },
        {
            label: 'Table',
            componentToRender: <MyTable fakeData={annualWages} title={annualWagesTitle}/>
        }
    ]
    const maxMinAnnualWages = [ //assuming data is sorted : max annual wages --> min annual wages
        {
            label: 'Max',
            componentToRender:
                <Flag title='Maximal Annual Wages (USD)'
                      country={annualWages[0]}
                />
        },
        {
            label: 'Min',
            componentToRender:
                <Flag title='Minimal Annual Wages (USD)'
                      country={annualWages[annualWages.length - 1]}
                />
        }

    ]

    return (
        <div className='checkbox-menu'>
            <div className='options-in-menu'>
                <h2>Average Size Class :</h2>
                {averageClassSize.map(option => {
                    const {label, componentToRender} = option;
                    return (
                        <CheckBox
                            key={label}
                            label={label}
                            ComponentToRender={componentToRender}
                        />
                    );
                })}
                <br/><br/>
                <h4>Most/Least Crowded Classes</h4>
                {maxMinClasses.map(country => {
                    const {label, componentToRender} = country;
                    return (
                        <CheckBox
                            key={label}
                            label={label}
                            ComponentToRender={componentToRender}
                        />
                    );
                })}

              <br/><br/><br/><br/>

                <h2>Average Annual Wages :</h2>
                {averageAnnualWages.map(option => {
                    const {label, componentToRender} = option;
                    return (
                        <CheckBox
                            key={label}
                            label={label}
                            ComponentToRender={componentToRender}
                        />
                    );
                })}
                <br/><br/>
                <h4>Max/Min Annual Wages</h4>
                {maxMinAnnualWages.map(country => {
                    const {label, componentToRender} = country;
                    return (
                        <CheckBox
                            key={label}
                            label={label}
                            ComponentToRender={componentToRender}
                        />
                    );
                })}
            </div>
        </div>
    );
}

export default CheckBoxMenu;