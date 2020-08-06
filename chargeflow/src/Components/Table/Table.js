import React from 'react';
import {withStyles, makeStyles} from '@material-ui/core/styles';
import Table from '@material-ui/core/Table';
import TableBody from '@material-ui/core/TableBody';
import TableCell from '@material-ui/core/TableCell';
import TableContainer from '@material-ui/core/TableContainer';
import TableHead from '@material-ui/core/TableHead';
import TableRow from '@material-ui/core/TableRow';
import Paper from '@material-ui/core/Paper';

const StyledTableCell = withStyles((theme) => ({
    head: {
        backgroundColor: 'darkBlue',
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
        minWidth: 1050,
        maxHeigth: 60,
        borderRadius: 20,

    },
});

const MyTable = ({user, markedValue}) => {
    const classes = useStyles();
    const styleMark = {color: '#FC3A5B', fontWeight: 'bold'};
    const getStyleOrder = () => {
        return markedValue === 'Orders' ? styleMark : null
    }
    const getStylePayment = () => {
        return markedValue === 'Payment' ? styleMark : null
    }

    return (
        <TableContainer component={Paper}>
            <Table className={classes.table} aria-label="customized table">
                <TableHead style={{color: 'blue'}}>
                    <TableRow>
                        <StyledTableCell>User Name</StyledTableCell>
                        <StyledTableCell style={getStyleOrder()}>Orders</StyledTableCell>
                        <StyledTableCell style={getStylePayment()}>Payment</StyledTableCell>
                    </TableRow>
                </TableHead>
                <TableBody>

                    <StyledTableRow key={user.firstName}>
                        <StyledTableCell> {`${user.firstName} ${user.lastName}`} </StyledTableCell>
                        <StyledTableCell> {user.numOfOrders} </StyledTableCell>
                        <StyledTableCell> {user.spent} </StyledTableCell>
                    </StyledTableRow>

                </TableBody>
            </Table>
        </TableContainer>
    );
}

export default MyTable;