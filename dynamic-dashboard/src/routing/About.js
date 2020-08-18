import React from "react";
import OECD from '../images/oecd-worldmap.svg'

const About = () => {
    return (
        <>
            <div className='about-text'>
                <h1>Who We Are</h1>
                <p> The Organisation for Economic Co-operation and Development (OECD) is an international organisation
                    that works to <br/>
                    build better policies for better lives. Our goal is to shape policies that foster prosperity,
                    equality, opportunity and <br/>
                    well-being for all. We draw on almost 60 years of experience and insights to better prepare the
                    world of tomorrow.
                    <br/>
                    <br/>

                    Together with governments, policy makers and citizens, we work on establishing evidence-based
                    international <br/>
                    standards and finding solutions to a range of social, economic and environmental challenges. From
                    improving <br/>
                    economic performance and creating jobs to fostering strong education and fighting international tax
                    evasion, we <br/>
                    provide a unique forum and knowledge hub for data and analysis, exchange of experiences,
                    best-practice sharing, <br/>
                    and advice on public policies and international standard-setting
                </p>
            </div>
            <img className='oecd-cover-image' src={OECD} draggable={false}/>
        </>
    );
}

export default About;