const {db} = require('../db/db_connection');


async function signUp (first_name, last_name, password, email) {
    try {
        await db.query(`INSERT INTO users (first_name, last_name, password, email)
                        VALUES ('${first_name}', '${last_name}', '${password}', '${email}')`);
    } catch (e) {
        throw e;
    }
}

async function signIn(email, password) {
    try {
        const result = await db.query(`SELECT password FROM users
                                        WHERE email='${email}'`);
        return password === result.rows[0].password;
    } catch (e) {
        throw e;
    }
}


async function getUserIdByEmail(email) {
    try {
        const result = await db.query(`SELECT user_id FROM users 
                                       WHERE email='${email}'`);

        return result.rows[0];
    } catch (e) {
        throw e;
    }
}


module.exports =  {
    signUp,
    signIn,
    getUserIdByEmail
};
