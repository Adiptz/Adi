import React from 'react';
import {withStyles, makeStyles} from '@material-ui/core/styles';
import Table from '@material-ui/core/Table';
import TableBody from '@material-ui/core/TableBody';
import TableCell from '@material-ui/core/TableCell';
import TableContainer from '@material-ui/core/TableContainer';
import TableHead from '@material-ui/core/TableHead';
import TableRow from '@material-ui/core/TableRow';
import Paper from '@material-ui/core/Paper';
import {Rnd} from "react-rnd";

const StyledTableCell = withStyles((theme) => ({
    head: {
        backgroundColor: '#2c3ac5',
        color: theme.palette.common.white,

    },
    body: {
        fontSize: 14,

    },
}))(TableCell);

const StyledTableRow = withStyles((theme) => ({
    root: {
        '&:nth-of-type(odd)': {
            backgroundColor: theme.palette.action.hover,
        },
    },
}))(TableRow);

const useStyles = makeStyles({
    table: {
        minWidth: 200,
        borderRadius: 20,
    },
});

const MyTable = ({fakeData, title}) => {
    const classes = useStyles();
    return (
        <Rnd default={{x: 300, y: 200}}>
            <TableContainer component={Paper}>
                <Table className={classes.table} aria-label="customized table">
                    <TableHead style={{color: 'blue'}}>
                        <TableRow>
                            <StyledTableCell>Country</StyledTableCell>
                            <StyledTableCell>{title}</StyledTableCell>
                        </TableRow>
                    </TableHead>

                    <TableBody>
                        {fakeData.map(country => {
                            const {name, averageClassSize, averageAnnualWages} = country;
                            return (
                                <StyledTableRow key={name}>
                                    <StyledTableCell> {name} </StyledTableCell>
                                    <StyledTableCell> {averageClassSize} {averageAnnualWages}</StyledTableCell>
                                </StyledTableRow>
                            )
                        })}

                    </TableBody>
                </Table>
            </TableContainer>
        </Rnd>
    );
}

export default MyTable;