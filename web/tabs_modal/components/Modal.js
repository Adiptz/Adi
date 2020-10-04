import React from 'react';
import {makeStyles, withStyles} from '@material-ui/core/styles';
import Tabs from '@material-ui/core/Tabs';
import Tab from '@material-ui/core/Tab';
import Typography from '@material-ui/core/Typography';

const AntTabs = withStyles({
    root: {
        borderBottom: '1px solid #e8e8e8',
    },
    indicator: {
        backgroundColor: '#EBD199',
    },
})(Tabs);

const AntTab = withStyles((theme) => ({
    root: {
        textTransform: 'none',
        minWidth: 72,
        fontWeight: theme.typography.fontWeightRegular,
        marginRight: theme.spacing(4),
        fontFamily: [
            '-apple-system',
            'BlinkMacSystemFont',
            '"Segoe UI"',
            'Roboto',
            '"Helvetica Neue"',
            'Arial',
            'sans-serif',
            '"Apple Color Emoji"',
            '"Segoe UI Emoji"',
            '"Segoe UI Symbol"',
        ].join(','),
        '&:hover': {
            color: '#EBD199',
            opacity: 1,
        },
        '&$selected': {
            color: '#EBD199',
            fontWeight: theme.typography.fontWeightMedium,
        },
        '&:focus': {
            color: '#EBD199',
        },
    },
    selected: {},
}))((props) => <Tab disableRipple {...props} />);

const StyledTabs = withStyles({
    indicator: {
        display: 'flex',
        justifyContent: 'center',
        backgroundColor: 'transparent',
        '& > span': {
            maxWidth: 40,
            width: '100%',
            backgroundColor: '#EBD199',
        },
    },
})((props) => <Tabs {...props} TabIndicatorProps={{children: <span/>}}/>);

const StyledTab = withStyles((theme) => ({
    root: {
        textTransform: 'none',
        color: '#EBD199',
        fontWeight: theme.typography.fontWeightRegular,
        fontSize: theme.typography.pxToRem(15),
        marginRight: theme.spacing(1),
        '&:focus': {
            opacity: 1,
        },
    },
}))((props) => <Tab disableRipple {...props} />);

const useStyles = makeStyles((theme) => ({
    root: {
        flexGrow: 1,
    },
    padding: {
        padding: theme.spacing(1.5),
    },
    demo1: {
        backgroundColor: theme.palette.background.paper,
    },
    demo2: {
        backgroundColor: '#2e1534',
        // borderRadius: '10px',
    },
}));

const SplitterContent = () => {
    return (
        <div className='example-content'>
            <label htmlFor="sub-kernels">Maximum number of sub-kernels:</label>
            <input type="text" id="sub-kernels" name="sub-kernels" value="250"/>

            <label htmlFor="dataset-mode">Choose a car:</label>
            <select id="dataset-mode" name="dataset-mode">
                <option value="All">All</option>
                <option value="Specific">Specific</option>
            </select>
        </div>
    )
}

const ScorersContent = () => {
    return (
        <div className='example-content'>
            <div className='checkbox'>
                <input type="checkbox" value="scorer1" />
                <label htmlFor="scorer1"> Clusters Probability Scorer </label>
            </div>
            <div className='checkbox'>
                <input type="checkbox" value="scorer2" />
                <label htmlFor="scorer2"> Home Scorer </label>
            </div>
            <div className='checkbox'>
                <input type="checkbox" value="scorer3" checked/>
                <label htmlFor="scorer3"> Count Cluster Scorer </label>
            </div>
            <div className='checkbox'>
                <input type="checkbox" value="scorer4" checked/>
                <label htmlFor="scorer4"> Normalized Count Cluster Scorer </label>
            </div>
            <div className='checkbox'>
                <input type="checkbox" value="scorer5" checked/>
                <label htmlFor="scorer5"> Sparse Scorer </label>
            </div>
        </div>
    )
}

export default function Modal() {
    const classes = useStyles();
    const [value, setValue] = React.useState(0);

    const handleChange = (event, newValue) => {
        setValue(newValue);
    };

    return (
        <div className='backdrop'>
            <div className='modal '>

                <div className={classes.demo2}>
                    <StyledTabs value={value} onChange={handleChange} aria-label="styled tabs example">
                        <StyledTab label="SPLITTER"/>
                        <StyledTab label="SCORERS"/>
                        <StyledTab label="MERGERS"/>
                        <StyledTab label="OTHERS"/>
                        <StyledTab label="OTHERS"/>

                    </StyledTabs>
                    <Typography className={classes.padding}/>
                </div>
                {value === 0 && <SplitterContent/>}
                {value === 1 && <ScorersContent/>}

                <button className='save-button'>Save</button>
            </div>
        </div>
    );
}
