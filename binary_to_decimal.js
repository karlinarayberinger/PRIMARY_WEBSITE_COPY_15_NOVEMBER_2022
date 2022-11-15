/**
 * file: binary_to_decimal.js
 * type: JavaScript
 * date: 15_AUGUST_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN
 */

/**
 * Display a time stamped message inside of the div element whose id is "output".
 * 
 * Set all light bulbs to "OFF" rather rather than "ON".
 * 
 * Set all binary digit values to zero (0) rather than one (1).
 * 
 * Set all buttons on the web page to visible.
 */
function initialize_application() {
    try {
        const time_point = Date.now(), p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>';
        let light_bulb_off = '<' + 'img src="light_bulb_off.png" width="60"' + '>', i = 0;
        const message = "The initialize_application() function was called at time: " + time_point + " milliseconds since 01_JANUARY_1970 00:00:00 (Coordinated Universal Time (UTC)).";
        console.log(message);
        document.getElementById("output").innerHTML = p0 + message + p1;
        for (i = 0; i < 8; i += 1) {
            document.getElementById("light_bulb_" + i).innerHTML = light_bulb_off;
            document.getElementById("bit_" + i).innerHTML = 0;
            document.getElementById("switch_" + i).style.display = "block";
        }
        document.getElementById("binary_to_decimal_button").style.display = "inline";
    }
    catch(exception) {
        console.log("An exception to expected functioning occurred during the runtime of the JavaScript function named initialize_application(): " + exception);
    }
}

/**
 * Change the binary state represented by the Nth light bulb in the array of 8 light bulbs to its only alternative state.
 * 
 * If the Nth bit value is set to 0, the Nth light bulb state is assumed to be "OFF".
 * 
 * If the Nth bit value is set to 1, the Nth light bulb state is assumed to be "ON".
 * 
 * When the switch for the Nth light bulb is clicked, the following will occur:
 * 
 * If the Nth bit is set to 0, then the Nth bit will be set to 1 and the Nth light bulb state will be set to "ON".
 * 
 * Otherwise, the Nth bit will be set to 0 and the Nth light bulb state will be set to "OFF".
 * 
 * @param {Number} N is assumed to be a base-ten integer no smaller than 0 and no larger than 7.
 */
function binary_switch(N) {
    try {
        let p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>', bit = undefined, light_bulb_image = undefined, light_bulb_off = '<' + 'img src="light_bulb_off.png" width="60"' + '>', light_bulb_on = '<' + 'img src="light_bulb_on.png" width="60"' + '>';
        bit = parseInt(document.getElementById("bit_" + N).innerHTML);
        if (bit === 0) {
            document.getElementById("bit_" + N).innerHTML = 1;
            document.getElementById("light_bulb_" + N).innerHTML = light_bulb_on;
        }
        else {
            document.getElementById("bit_" + N).innerHTML = 0;
            document.getElementById("light_bulb_" + N).innerHTML = light_bulb_off; 
        }
    }
    catch(exception) {
        console.log("An exception to expected functioning occurred during the runtime of the JavaScript function named binary_switch(N): " + exception);
    }
}

/**
 * Change the binary state represented by the 7th (i.e. seventh) light bulb in the array of 8 light bulbs to its only alternative state.
 * 
 * Note that the 7th light bulb represents the highest order bit and is the leftmost light bulb in the array.
 * 
 * If the 7th bit value is set to 0, the 7th light bulb state is assumed to be "OFF".
 * 
 * If the 7th bit value is set to 1, the 7th light bulb state is assumed to be "ON".
 * 
 * When the switch for the 7th light bulb is clicked, the following will occur:
 * 
 * If the 7th bit is set to 0, then the Nth bit will be set to 1 and the 7th light bulb state will be set to "ON".
 * 
 * Otherwise, the 7th bit will be set to 0 and the 7th light bulb state will be set to "OFF".
 */
function switch_7() { 
    const time_point = Date.now();
    console.log("The switch_7 button was clicked at time: " + time_point + " milliseconds since 01_JANUARY_1970 00:00:00 (Coordinated Universal Time (UTC)).");
    binary_switch(7); 
}

/**
 * Change the binary state represented by the 6th (i.e. sixth) light bulb in the array of 8 light bulbs to its only alternative state.
 * 
 * If the 6th bit value is set to 0, the 6th light bulb state is assumed to be "OFF".
 * 
 * If the 6th bit value is set to 1, the 6th light bulb state is assumed to be "ON".
 * 
 * When the switch for the 6th light bulb is clicked, the following will occur:
 * 
 * If the 6th bit is set to 0, then the 6th bit will be set to 1 and the 6th light bulb state will be set to "ON".
 * 
 * Otherwise, the 6th bit will be set to 0 and the 6th light bulb state will be set to "OFF".
 */
function switch_6() { 
    const time_point = Date.now();
    console.log("The switch_6 button was clicked at time: " + time_point + " milliseconds since 01_JANUARY_1970 00:00:00 (Coordinated Universal Time (UTC)).");
    binary_switch(6); 
}

/**
 * Change the binary state represented by the 5th (i.e. fifth) light bulb in the array of 8 light bulbs to its only alternative state.
 * 
 * If the 5th bit value is set to 0, the 5th light bulb state is assumed to be "OFF".
 * 
 * If the 5th bit value is set to 1, the 5th light bulb state is assumed to be "ON".
 * 
 * When the switch for the 5th light bulb is clicked, the following will occur:
 * 
 * If the 5th bit is set to 0, then the 5th bit will be set to 1 and the 5th light bulb state will be set to "ON".
 * 
 * Otherwise, the 5th bit will be set to 0 and the 5th light bulb state will be set to "OFF".
 */
function switch_5() { 
    const time_point = Date.now();
    console.log("The switch_5 button was clicked at time: " + time_point + " milliseconds since 01_JANUARY_1970 00:00:00 (Coordinated Universal Time (UTC)).");
    binary_switch(5); 
}

/**
 * Change the binary state represented by the 4th (i.e. fourth) light bulb in the array of 8 light bulbs to its only alternative state.
 * 
 * If the 4th bit value is set to 0, the 4th light bulb state is assumed to be "OFF".
 * 
 * If the 4th bit value is set to 1, the 4th light bulb state is assumed to be "ON".
 * 
 * When the switch for the 4th light bulb is clicked, the following will occur:
 * 
 * If the 4th bit is set to 0, then the 4th bit will be set to 1 and the 4th light bulb state will be set to "ON".
 * 
 * Otherwise, the 4th bit will be set to 0 and the 4th light bulb state will be set to "OFF".
 */
function switch_4() { 
    const time_point = Date.now();
    console.log("The switch_4 button was clicked at time: " + time_point + " milliseconds since 01_JANUARY_1970 00:00:00 (Coordinated Universal Time (UTC)).");
    binary_switch(4); 
}

/**
 * Change the binary state represented by the 3rd (i.e. third) light bulb in the array of 8 light bulbs to its only alternative state.
 * 
 * If the 3rd bit value is set to 0, the 3rd light bulb state is assumed to be "OFF".
 * 
 * If the 3rd bit value is set to 1, the 3rd light bulb state is assumed to be "ON".
 * 
 * When the switch for the 3rd light bulb is clicked, the following will occur:
 * 
 * If the 3rd bit is set to 0, then the 3rd bit will be set to 1 and the 3rd light bulb state will be set to "ON".
 * 
 * Otherwise, the 3rd bit will be set to 0 and the 3rd light bulb state will be set to "OFF".
 */
function switch_3() { 
    const time_point = Date.now();
    console.log("The switch_3 button was clicked at time: " + time_point + " milliseconds since 01_JANUARY_1970 00:00:00 (Coordinated Universal Time (UTC)).");
    binary_switch(3); 
}

/**
 * Change the binary state represented by the 2nd (i.e. second) light bulb in the array of 8 light bulbs to its only alternative state.
 * 
 * If the 2nd bit value is set to 0, the 2nd light bulb state is assumed to be "OFF".
 * 
 * If the 2nd bit value is set to 1, the 2nd light bulb state is assumed to be "ON".
 * 
 * When the switch for the 2nd light bulb is clicked, the following will occur:
 * 
 * If the 2nd bit is set to 0, then the 2nd bit will be set to 1 and the 2nd light bulb state will be set to "ON".
 * 
 * Otherwise, the 2nd bit will be set to 0 and the 2nd light bulb state will be set to "OFF".
 */
function switch_2() { 
    const time_point = Date.now();
    console.log("The switch_2 button was clicked at time: " + time_point + " milliseconds since 01_JANUARY_1970 00:00:00 (Coordinated Universal Time (UTC)).");
    binary_switch(2); 
}

/**
 * Change the binary state represented by the 1st (i.e. first) light bulb in the array of 8 light bulbs to its only alternative state.
 * 
 * If the 1st bit value is set to 0, the 1st light bulb state is assumed to be "OFF".
 * 
 * If the 1st bit value is set to 1, the 1st light bulb state is assumed to be "ON".
 * 
 * When the switch for the 1st light bulb is clicked, the following will occur:
 * 
 * If the 1st bit is set to 0, then the 1st bit will be set to 1 and the 1st light bulb state will be set to "ON".
 * 
 * Otherwise, the 1st bit will be set to 0 and the 1st light bulb state will be set to "OFF".
 */
function switch_1() { 
    const time_point = Date.now();
    console.log("The switch_1 button was clicked at time: " + time_point + " milliseconds since 01_JANUARY_1970 00:00:00 (Coordinated Universal Time (UTC)).");
    binary_switch(1); 
}

/**
 * Change the binary state represented by the 0th (i.e. zeroth) light bulb in the array of 8 light bulbs to its only alternative state.
 * 
 * Note that the 0th light bulb represents the lowest order bit and is the rightmost light bulb in the array.
 * 
 * If the 0th bit value is set to 0, the 0th light bulb state is assumed to be "OFF".
 * 
 * If the 0th bit value is set to 1, the 0th light bulb state is assumed to be "ON".
 * 
 * When the switch for the 1st light bulb is clicked, the following will occur:
 * 
 * If the 0th bit is set to 0, then the 0th bit will be set to 1 and the 1st light bulb state will be set to "ON".
 * 
 * Otherwise, the 0th bit will be set to 0 and the 0th light bulb state will be set to "OFF".
 */
function switch_0() { 
    const time_point = Date.now();
    console.log("The switch_0 button was clicked at time: " + time_point + " milliseconds since 01_JANUARY_1970 00:00:00 (Coordinated Universal Time (UTC)).");
    binary_switch(0); 
}

/**
 * Hide all buttons except for the RESET button.
 * 
 * Convert the input binary number to its logically equivalent decimal number and display the arithmetic steps inside the div whose id is "output".
 */
function binary_to_decimal() {
    try {
        const time_point = Date.now(), p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>', s0 = '<' + 'span class="console"' + '>', s1 = '<' + '/' + 'span' + '>';
        let i = 0, binary_digits_string = "", decimal_output_number = 0, decimal_term_value = 0,  arithmetic_steps = "", message = "";
        message = "The BINARY_TO_DECIMAL button was clicked at time: " + time_point + " milliseconds since 01_JANUARY_1970 00:00:00 (Coordinated Universal Time (UTC)).";
        console.log(message);
        document.getElementById("output").innerHTML += p0 + message + p1;
        for (i = 0; i < 8; i += 1) document.getElementById("switch_" + i).style.display = "none";
        document.getElementById("binary_to_decimal_button").style.display = "none";
        for (i = 7; i > -1; i -= 1) binary_digits_string += document.getElementById("bit_" + i).innerHTML;
        console.log("The input binary digit sequence is " + binary_digits_string + ".");
        for (i = 7; i > -1; i -= 1) {
            decimal_term_value = parseInt(binary_digits_string[i]) * Math.pow(2, 7 - i);
            decimal_output_number += decimal_term_value;
            
        }
        console.log("The output decimal digit sequence is " + decimal_output_number + ".");
        arithmetic_steps += p0 + "binary_input: " + s0 + binary_digits_string + s1 + "." + p1;
        arithmetic_steps += p0 + "decimal_output: " + decimal_output_number + "." + p1;
        arithmetic_steps += p0 + "arithmetic_steps: " + p1;
        arithmetic_steps += p0 + decimal_output_number + " = " + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[0] + s1 + " * (2 ^ 7)) +" + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[1] + s1 + " * (2 ^ 6)) +" + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[2] + s1 + " * (2 ^ 5)) +" + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[3] + s1 + " * (2 ^ 4)) +" + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[4] + s1 + " * (2 ^ 3)) +" + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[5] + s1 + " * (2 ^ 2)) +" + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[6] + s1 + " * (2 ^ 1)) +" + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[7] + s1 + " * (2 ^ 0)) = " + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[0] + s1 + " * 128) +" + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[1] + s1 + " * 64) +" + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[2] + s1 + " * 32) +" + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[3] + s1 + " * 16) +" + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[4] + s1 + " * 8) +" + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[5] + s1 + " * 4) +" + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[6] + s1 + " * 2) +" + p1;
        arithmetic_steps += p0 + "(" + s0 + binary_digits_string[7] + s1 + " * 1) = " + p1;
        arithmetic_steps += p0 + parseInt(binary_digits_string[0]) * 128 + " + " + p1;
        arithmetic_steps += p0 + parseInt(binary_digits_string[1]) * 64 + " + " + p1;
        arithmetic_steps += p0 + parseInt(binary_digits_string[2]) * 32 + " + " + p1;
        arithmetic_steps += p0 + parseInt(binary_digits_string[3]) * 16 + " + " + p1;
        arithmetic_steps += p0 + parseInt(binary_digits_string[4]) * 8 + " + " + p1;
        arithmetic_steps += p0 + parseInt(binary_digits_string[5]) * 4 + " + " + p1;
        arithmetic_steps += p0 + parseInt(binary_digits_string[6]) * 2 + " + " + p1;
        arithmetic_steps += p0 + parseInt(binary_digits_string[7]) * 1 + "." + p1;
        document.getElementById("output").innerHTML += arithmetic_steps;
    }
    catch(exception) {
        console.log("An exception to expected functioning occurred during the runtime of the JavaScript function named binary_to_decimal(): " + exception);
    }
}
