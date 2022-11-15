/**
 * file: hexidecimal_color_codes.js
 * type: JavaScript
 * date: 17_AUGUST_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN
 */

/**
 * Set the web page interface to its initial state.
 * 
 * Display a placeholder paragraph inside of the div element whose id is "output".
 * 
 * Assume that this function is called in response to the event of the corresponding web page, 
 * hexidecimal_color_codes.html, being loaded by the web browser.
 */
function initialize_application() {
    try {
        const time_stamp = generate_time_stamp(), p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>';
        let message = "The web page, hexidecimal_color_codes.html, was loaded at time: " + time_stamp;
        console.log(message);
        document.getElementById("time_stamped_events").innerHTML = p0 + message + p1;
        document.getElementById("output").innerHTML = p0 + "This sentence will disappear when the GENERATE button is clicked." + p1;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of initialize_application(): " + exception);
    }
}

/**
 * Return the value of the selected menu option of a select menu element.
 * 
 * @param {String} select_menu_identifier is assumed to be the id of a select HTML element.
 * 
 * @return {String} the value of the selected menu option.
 */
function get_selected_menu_option_value(select_menu_identifier) {
    try {
        let menu_object = {}, options_array = [], selected_option_index = 0, selected_option_object = {}, selected_option_value;
        menu_object = document.getElementById(select_menu_identifier);
        options_array = menu_object.options;
        selected_option_index = menu_object.selectedIndex;
        selected_option_object = options_array[selected_option_index];
        selected_option_value = selected_option_object.value
        return selected_option_value;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of get_selected_menu_option(select_menu_identifier): " + exception);
    }
}

/**
 * Use the native JavaScript Math library function for generating random numbers to select a 
 * base-ten number no smaller than 0 and less than 1.
 * 
 * @return {Number} a base-ten (i.e. decimal) number no smaller than zero and smaller than one.
 */
function generate_random_nonnegative_number_less_than_one() {
    return Math.random();
}

/**
 * Use the native JavaScript Math library function for generating random numbers to select a base-ten 
 * number no smaller than 0 and less than 1 and store the result in a variable named N.
 * 
 * Multiply N by 256, round the result down to the nearest integer, and return that rounded down result.
 * 
 * @return {Number} a base-ten (i.e. decimal) integer no smaller than 0 and no larger than 255.
 */
function generate_random_nonnegative_integer_less_than_two_hundred_fifty_six() {
    let N = generate_random_nonnegative_number_less_than_one();
    return Math.floor(N * 256);
}

/**
 * Convert a nonnegative decimal integer which is no smaller than 0 and no larger than 255 to its two-digit hexidecimal equivalent.
 * 
 * @param {Number} decimal_integer is assumed to be a base-ten integer no smaller than 0 and no larger than 255.
 * 
 * @return {String} a sequence of two hexidecimal digits which represents the same numerical value as decimal_integer.
 */
function convert_from_decimal_to_hexidecimal(decimal_integer) {
    try {
        let hexidecimal_digits_set = "0123456789ABCDEF";
        let hexidecimal_output_array = ['0','0'];
        let hexidecimal_output_string = "";
        if (arguments.length !== 1) throw "exactly one function argument is required.";
        if (typeof arguments[0] !== "number") throw "decimal_integer must be a Number type value.";
        if (decimal_integer !== Math.floor(decimal_integer)) throw "decimal_integer must be a whole number value.";
        if (decimal_integer < 0) throw "decimal_integer must be a nonnegative number value.";
        if (decimal_integer > 255) throw "decicmal_integer must not exceed 255.";
        hexidecimal_output_array[0] = hexidecimal_digits_set[decimal_integer % 16];
        decimal_integer = Math.floor(decimal_integer / 16);
        hexidecimal_output_array[1] = hexidecimal_digits_set[decimal_integer % 16];
        hexidecimal_output_string += hexidecimal_output_array[1];
        hexidecimal_output_string += hexidecimal_output_array[0];
        return hexidecimal_output_string;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of convert_from_decimal_to_hexidecimal(decimal_integer): " + exception);
        return "00";
    }
}

/**
 * Generate a random hexidecimal color code string in the format "#RRGGBB" where RR represents the RED gradient, 
 * GG represents the GREEN gradient, and BB represents the BLUE gradient (and where each of the three "primary color"
 * gradients is a sequence of two hexidecimal digits which represents a decimal integer no 
 * smaller than 0 and no larger than 255)).
 * 
 * If color_skew_specification is "red", the decimal number which "RR" represents will be 
 * larger than or equal to the decimal number represented by "GG" and larger or equal to 
 * the decimal number represented by "BB".
 * 
 * If color_skew_specification is "green", the decimal number which "GG" represents will be 
 * larger than or equal to the decimal number represented by "RR" and larger or equal to 
 * the decimal number represented by "BB".
 * 
 * If color_skew_specification is "blue", the decimal number which "BB" represents will be 
 * larger than or equal to the decimal number represented by "RR" and larger or equal to 
 * the decimal number represented by "GG".
 * 
 * If color_skew_specification is neither "red", "green", or "blue", then no color skew 
 * will be applied (i.e. the color_skew_specification value will be treated as though it were "none").
 * 
 * Note that a hexidecimal digit is a String type character from the following set of sixteen 
 * base-sixteen digits (which are listed in ascending order such that each hexidecimal digit 
 * represents a base-ten integer value starting with 0 and incrementing by exactly 1): 
 * 
 * ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'].
 * 
 * @param {String} color_skew_specification is assumed to be either "none", "red", "green", or "blue".
 * 
 * @return {String} a hexidecimal color code string in the format "#RRGGBB".
 */
function generate_random_hexidecimal_color_code(color_skew_specification) {
    try {
        let red_gradient_hexidecimal_digits_sequence = "00", red_gradient_decimal_value = 0;
        let green_gradient_hexidecimal_digits_sequence = "00", green_gradient_decimal_value = 0;
        let blue_gradient_hexidecimal_digits_sequence = "00", blue_gradient_decimal_value = 0;
        if (arguments.length !== 1) throw "exactly one function argument is required.";
        if (typeof arguments[0] !== "string") throw "color_skew_specification must be a String type value.";
        red_gradient_decimal_value = generate_random_nonnegative_integer_less_than_two_hundred_fifty_six();
        green_gradient_decimal_value = generate_random_nonnegative_integer_less_than_two_hundred_fifty_six();
        blue_gradient_decimal_value = generate_random_nonnegative_integer_less_than_two_hundred_fifty_six();
        if (color_skew_specification === "red") {
            while ((red_gradient_decimal_value < green_gradient_decimal_value) || (red_gradient_decimal_value < blue_gradient_decimal_value)) {
                red_gradient_decimal_value = generate_random_nonnegative_integer_less_than_two_hundred_fifty_six();
                green_gradient_decimal_value = generate_random_nonnegative_integer_less_than_two_hundred_fifty_six();
                blue_gradient_decimal_value = generate_random_nonnegative_integer_less_than_two_hundred_fifty_six();
            }
        }
        if (color_skew_specification === "green") {
            while ((green_gradient_decimal_value < red_gradient_decimal_value) || (green_gradient_decimal_value < blue_gradient_decimal_value)) {
                red_gradient_decimal_value = generate_random_nonnegative_integer_less_than_two_hundred_fifty_six();
                green_gradient_decimal_value = generate_random_nonnegative_integer_less_than_two_hundred_fifty_six();
                blue_gradient_decimal_value = generate_random_nonnegative_integer_less_than_two_hundred_fifty_six();
            }
        }
        if (color_skew_specification === "blue") {
            while ((blue_gradient_decimal_value < red_gradient_decimal_value) || (blue_gradient_decimal_value < green_gradient_decimal_value)) {
                red_gradient_decimal_value = generate_random_nonnegative_integer_less_than_two_hundred_fifty_six();
                green_gradient_decimal_value = generate_random_nonnegative_integer_less_than_two_hundred_fifty_six();
                blue_gradient_decimal_value = generate_random_nonnegative_integer_less_than_two_hundred_fifty_six();
            }
        }
        red_gradient_hexidecimal_digits_sequence = convert_from_decimal_to_hexidecimal(red_gradient_decimal_value);
        green_gradient_hexidecimal_digits_sequence = convert_from_decimal_to_hexidecimal(green_gradient_decimal_value);
        blue_gradient_hexidecimal_digits_sequence = convert_from_decimal_to_hexidecimal(blue_gradient_decimal_value);
        return "#" + red_gradient_hexidecimal_digits_sequence + green_gradient_hexidecimal_digits_sequence + blue_gradient_hexidecimal_digits_sequence;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of generate_random_hexidecimal_color_code(color_skew_specification): " + exception);
        return "#000000";
    }
}

/**
 * Return the decimal integer index of the hexidecimal digit which H represents where 
 * hexidecimal digits are the following set of characters arranged in the following permutation:
 * 
 * ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
 * 
 * @param {String} H is assumed to be a single hexidecimal digit.
 * 
 * @return {Number} the decimal integer index of the hexidecimal digit which H represents.
 */
function get_decimal_value_of_hexidecimal_digit(H) {
    if (H === '0') return 0;
    if (H === '1') return 1;
    if (H === '2') return 2;
    if (H === '3') return 3;
    if (H === '4') return 4;
    if (H === '5') return 5;
    if (H === '6') return 6;
    if (H === '7') return 7;
    if (H === '8') return 8;
    if (H === '9') return 9;
    if (H === 'A') return 10;
    if (H === 'B') return 11;
    if (H === 'C') return 12;
    if (H === 'D') return 13;
    if (H === 'E') return 14;
    if (H === 'F') return 15;
    return 0;
}

/**
 * Convert a string comprised of exactly two hexidecimal digits to its corresponding decimal representation.
 * 
 * Note that the characters comprising hexidecimal_sequence must be members of the following set:
 * 
 * ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
 * 
 * Note that the output value will be a decimal integer no smaller than 0 and no larger than 255.
 * 
 * @param {String} hexidecimal_sequence is assumed to be a string comprised of exactly two hexidecimal digits.
 * 
 * @return {Number} the base-ten number which hexidecimal_sequence represents.
 */
function convert_from_hexidecimal_to_decimal(hexidecimal_sequence) {
    try {
        let hexidecimal_digits_set = "0123456789ABCDEF", i = 0, is_valid_hexidecimal_digit = false, decimal_output = 0;
        if (arguments.length !== 1) throw "exactly one function argument is required.";
        if (typeof arguments[0] !== "string") throw "hexidecimal_sequence must be a String type value.";
        if (hexidecimal_sequence.length !== 2) throw "hexidecimal_sequence must have a length of exactly 2 characters.";
        for (i = 0; i < 16; i += 1) if (hexidecimal_sequence[0] === hexidecimal_digits_set[i]) is_valid_hexidecimal_digit = true;
        if (!is_valid_hexidecimal_digit) throw "The first digit of hexidecimal_sequence is not a valid hexidecimal digit.";
        is_valid_hexidecimal_digit = false;
        for (i = 0; i < 16; i += 1) if (hexidecimal_sequence[1] === hexidecimal_digits_set[i]) is_valid_hexidecimal_digit = true;
        if (!is_valid_hexidecimal_digit) throw "The second digit of hexidecimal_sequence is not a valid hexidecimal digit.";
        decimal_output += (get_decimal_value_of_hexidecimal_digit(hexidecimal_sequence[0]) * 16);
        decimal_output += (get_decimal_value_of_hexidecimal_digit(hexidecimal_sequence[1]));
        return decimal_output;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of convert_from_hexidecimal_to_decimal(hexidecimal_sequence): " + exception);
        return 0;   
    }
}

/**
 * Generate the HTML string which constructs a table data cell whose text content is as follows:
 * 
 * - hexidecimal_color_code:    a randomly generated hexidecimal color code string in the format "#RRGGBB" 
 *                              where RR represents the RED gradient, GG represents the GREEN gradient, 
 *                              and BB represents the BLUE gradient (and where each of the three "primary color"
 *                              gradients is a sequence of two hexidecimal digits which represents a decimal 
 *                              integer no smaller than 0 and no larger than 255)).
 * 
 * - red_value: a decimal integer no smaller than 0 and no larger than 255 which "RR" represents.
 * 
 * - green_value: a decimal integer no smaller than 0 and no larger than 255 which "GG" represents.
 * 
 * - blue_value: a decimal integer no smaller than 0 and no larger than 255 which "BB" represents.
 * 
 * If color_skew_specification is "red", the decimal number which "RR" represents will be 
 * larger than or equal to the decimal number represented by "GG" and larger or equal to 
 * the decimal number represented by "BB".
 * 
 * If color_skew_specification is "green", the decimal number which "GG" represents will be 
 * larger than or equal to the decimal number represented by "RR" and larger or equal to 
 * the decimal number represented by "BB".
 * 
 * If color_skew_specification is "blue", the decimal number which "BB" represents will be 
 * larger than or equal to the decimal number represented by "RR" and larger or equal to 
 * the decimal number represented by "GG".
 * 
 * If color_skew_specification is neither "red", "green", or "blue", then no color skew 
 * will be applied (i.e. the color_skew_specification value will be treated as though it were "none").           
 * 
 * @param {String} color_skew_specification is assumed to be either "none", "red", "green", or "blue".
 * 
 * @return {String} the HTML string which may be used to construct a table data element on a web page.
 */
function generate_html_string_for_table_cell(color_skew_specification) {
    let html_string = "", hexidecimal_color_code = "", RR = "", GG = "", BB = "", red_value = 0, green_value = 0, blue_value = 0;
    hexidecimal_color_code = generate_random_hexidecimal_color_code(color_skew_specification);
    RR += hexidecimal_color_code[1];
    RR += hexidecimal_color_code[2];
    GG += hexidecimal_color_code[3];
    GG += hexidecimal_color_code[4];
    BB += hexidecimal_color_code[5];
    BB += hexidecimal_color_code[6];
    red_value = convert_from_hexidecimal_to_decimal(RR);
    green_value = convert_from_hexidecimal_to_decimal(GG);
    blue_value = convert_from_hexidecimal_to_decimal(BB);
    html_string += '<' + 'td' + ' style="background:' +  hexidecimal_color_code + '"' + '>';
    html_string += '<' + 'p' + ' class="tile_text"' + '>';
    html_string += "hexidecimal_color_code: " + hexidecimal_color_code;
    html_string += '<' + '/' + 'p' + '>';
    html_string += '<' + 'p' + ' class="tile_text"' + '>';
    html_string += "red_value: " + red_value;
    html_string += '<' + '/' + 'p' + '>';
    html_string += '<' + 'p' + ' class="tile_text"' + '>';
    html_string += "green_value: " + green_value;
    html_string += '<' + '/' + 'p' + '>';
    html_string += '<' + 'p' + ' class="tile_text"' + '>';
    html_string += "blue_value: " + blue_value;
    html_string += '<' + '/' + 'p' + '>';
    html_string += '<' + '/' + 'td' + '>';
    return html_string;
}

/**
 * Populate the div element whose id is "output" with a table consisting of three rows, three columns, 
 * and cells whose background color is set to the hexidecimal color code text displayed in the respective cell.
 * 
 * Each of the nine hexidecimal color codes is a randomly generated String value whose RED-GREEN-BLUE values are 
 * constrained according to the option selected in the select menu whose id is "color_skew_menu".
 * 
 * Assume that this function is called in response to the event of button on the corresponding web page, 
 * hexidecimal_color_codes.html, whose value is "GENERATE" being clicked.
 */
function generate_color_grid() {
    try {        
        const time_stamp = generate_time_stamp(), p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>';
        let message = "The GENERATE button was clicked at time: " + time_stamp;
        let selected_color_skew = "", output_div_content = "";
        console.log(message);
        document.getElementById("time_stamped_events").innerHTML += p0 + message + p1;
        selected_color_skew = get_selected_menu_option_value("color_skew_menu");
        output_div_content = '<' + 'p' + '>';
        output_div_content += "selected_color_skew := " + selected_color_skew + ".";
        output_div_content += '<' + '/' + 'p' + '>';
        output_div_content += '<' + 'table' + '>';
        output_div_content += '<' + 'tr' + '>';
        output_div_content += generate_html_string_for_table_cell(selected_color_skew);
        output_div_content += generate_html_string_for_table_cell(selected_color_skew);
        output_div_content += generate_html_string_for_table_cell(selected_color_skew);
        output_div_content += '<' + '/' + 'tr' + '>';
        output_div_content += '<' + 'tr' + '>';
        output_div_content += generate_html_string_for_table_cell(selected_color_skew);
        output_div_content += generate_html_string_for_table_cell(selected_color_skew);
        output_div_content += generate_html_string_for_table_cell(selected_color_skew);
        output_div_content += '<' + '/' + 'tr' + '>';
        output_div_content += '<' + 'tr' + '>';
        output_div_content += generate_html_string_for_table_cell(selected_color_skew);
        output_div_content += generate_html_string_for_table_cell(selected_color_skew);
        output_div_content += generate_html_string_for_table_cell(selected_color_skew);
        output_div_content += '<' + '/' + 'tr' + '>';
        output_div_content += '<' + '/' + 'table' + '>';
        document.getElementById("output").innerHTML = output_div_content;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of generate_color_grid(): " + exception);
    }
}
