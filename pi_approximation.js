/**
 * file: pi_approximation.js
 * type: JavaScript
 * date: 15_AUGUST_2022
 * author: Karlina Ray Beringer
 * license: PUBLIC_DOMAIN
 */

/**
 * Generate a random x-value or a random y-value for a planar coordinate pair.
 * 
 * @return {Number} an integer no smaller than -200 and no larger than 200.
 */
function generate_random_coordinate_scalar() {
	let random_nonnegative_integer_less_than_201 = Math.floor(Math.random() * 201);
	let random_number_sign = (Math.floor(Math.random() * 100) % 2 === 0) ? 1 : -1;
	return random_number_sign * random_nonnegative_integer_less_than_201;
}

/**
 * Generate a random coordinate pair for plotting points on a Cartesian plane whose origin is represented by 
 * the coordinate pair { x_coordinate: 0, y_coordinate: 0} and whose side lengths are no less than 400 units.
 * 
 * @return {Object} a planar point representation where the x-coordinate (i.e. horizontal position) 
 *                  and the y-coordinate (i.e. vertical position) is each no smaller than -200 and no larger than 200.
 */
function generate_random_planar_point() {
	return { x_coordinate : generate_random_coordinate_scalar(), y_coordinate: generate_random_coordinate_scalar() };
}

/**
 * Compute the approximate square root of input such that the output has an arbitrary number of significant digits.
 * The product, approximate_square_root(input) * approximate_square_root(input), is approximately equal to input. 
 * 
 * @param {Number} input is assumed to be a nonnegative integer.
 * 
 * @return {Number} the approximate square root of input.
 */
function approximate_square_root(input) {
	let n = 0, a = 0, b = 0, c = 0;
	try {
		if (arguments.length !== 1) throw "exactly one function argument is required.";
		if (typeof arguments[0] !== "number") throw "the function argument must be a Number type value.";
		if (input < 0) throw "the function argument must be no smaller than zero.";
		n = input;
		a = n;
		b = 1;
		c = 0.000000001; // precision control
		while ((a - b) > c) { 
			a = (a + b) / 2;
			b = n / a;
		}
		return a;
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in approximate_square_root(input): " + exception);
		return 0;
	}
}

/**
 * Determine whether or not a given input value is a valid planar point object (as defined in the generate_random_planar_point() function).
 * 
 * @param {Object} input is assumed to be an object with the following properties: 
 * 		{Number} x_coordinate is assumed to be an integer no smaller than -200 and no larger than 200.
 *       	{Number} y_coordinate is assumed to be an integer no smaller than -200 and no larger than 200.
 * 
 * @return {Boolean} true if input satisfies the conditions defined above; false otherwise.
 */
function is_point(input) {
	try {
		if (arguments.length !== 1) throw "exactly one function argument is required.";
		if (typeof input.x_coordinate !== "number") throw "the x_coordinate property of input must be a Number type value.";
		if (typeof input.y_coordinate !== "number") throw "the y_coordinate property of input must be a Number type value.";
		if (Math.floor(input.x_coordinate) !== input.x_coordinate) throw "the x_coordinate property of the input object must be a whole number value.";
		if (Math.floor(input.y_coordinate) !== input.y_coordinate) throw "the y_coordinate property of the input object must be a whole number value.";
		if ((input.x_coordinate < -200) || (input.x_coordinate > 200)) throw "the x_coordinate property of the input object must be no smaller than -200 and no larger than 200.";
		if ((input.y_coordinate < -200) || (input.y_coordinate > 200)) throw "the y_coordinate property of the input object must be no smaller than -200 and no larger than 200.";
		return true;
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in is_point(input): " + exception);
		return false;
	}
}

/**
 * Use the Distance Formula to calculate the nonnegative real number distance between planar points A and B.
 * 
 * distance_formula(A, B) = square_root( ((A.x - B.x) ^ 2) + ((A.y - B.y) ^ 2) )
 * 
 * @param {Object} A is assumed to be an object with the following properties: 
 * 			{Number} x_coordinate is assumed to be an integer no smaller than -200 and no larger than 200.
 *    			{Number} y_coordinate is assumed to be an integer no smaller than -200 and no larger than 200.
 *
 * @param {Object} B is assumed to be an object with the following properties: 
 * 			{Number} x_coordinate is assumed to be an integer no smaller than -200 and no larger than 200.
 *       		{Number} y_coordinate is assumed to be an integer no smaller than -200 and no larger than 200.
 * 
 * @return {Number} the length of the shortest path between planar points A and B.
 */
function compute_distance_between_two_planar_points(A, B) {
	let horizontal_difference = 0, vertical_difference = 0;
	try {
		if (arguments.length !== 2) throw "exactly two function arguments are required.";
		if (!is_point(A)) throw "A must be an object whose properties are as follows: { x_coordinate : integer in range [-200,200], y_coordinate : integer in range [-200,200] }.";
		if (!is_point(B)) throw "B must be an object whose properties are as follows: { x_coordinate : integer in range [-200,200], y_coordinate : integer in range [-200,200] }.";
		horizontal_difference = A.x_coordinate - B.x_coordinate;
		vertical_difference = A.y_coordinate - B.y_coordinate;
		return approximate_square_root((horizontal_difference * horizontal_difference) + (vertical_difference * vertical_difference));
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in compute_distance_between_two_planar_points(A, B): " + exception);
		return 0;
	}
}

/**
 * Add one to the number which is enclosed inside the HTML span element whose id is "red_pixel_count_span" on the corresponding web page.
 * 
 * Assume that the number of red pixels is a nonnnegative integer no larger than 3600.
 */
function increment_red_pixel_count() {
	let red_pixel_count_span = undefined, red_pixel_count = 0;
	try {
		red_pixel_count_span = document.getElementById("red_pixel_count_span");
		red_pixel_count = parseInt(red_pixel_count_span.innerHTML);
		if ((red_pixel_count < 0) || (red_pixel_count > 3600)) throw "red_pixel_count must be an integer no smaller than 0 and no larger than 3600.";
		red_pixel_count += 1;
		red_pixel_count_span.innerHTML = red_pixel_count;
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in increment_red_pixel_count(): " + exception);
	}
}

/**
 * Add one to the number which is enclosed inside the HTML span element whose id is "blue_pixel_count_span" on the corresponding web page.
 * 
 * Assume that the number of blue pixels is a nonnnegative integer no larger than 3600.
 */
function increment_blue_pixel_count() {
	let blue_pixel_count_span = undefined, blue_pixel_count = 0;
	try {
		blue_pixel_count_span = document.getElementById("blue_pixel_count_span");
		blue_pixel_count = parseInt(blue_pixel_count_span.innerHTML);
		if ((blue_pixel_count < 0) || (blue_pixel_count > 3600)) throw "blue_pixel_count must be an integer no smaller than 0 and no larger than 3600.";
		blue_pixel_count += 1;
		blue_pixel_count_span.innerHTML = blue_pixel_count;
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in increment_blue_pixel_count(): " + exception);
	}
}

/**
 * Retrieve the number which is enclosed inside the HTML span element whose id is "red_pixel_count_span" on the corresponding web page.
 * 
 * Assume that the number of red pixels is a nonnnegative integer no larger than 3600.
 * 
 * @return {Number} an integer representing the total number of red pixel-sized "darts" which have been plotted on the HTML canvas element on the corresponding web page.
 */
function get_red_pixel_count() {
	let red_pixel_count_span = undefined, red_pixel_count = 0;
	try {
		red_pixel_count_span = document.getElementById("red_pixel_count_span");
		red_pixel_count = parseInt(red_pixel_count_span.innerHTML);
		if ((red_pixel_count < 0) || (red_pixel_count > 3600)) throw "red_pixel_count must be an integer no smaller than 0 and no larger than 3600.";
		return red_pixel_count;
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in get_red_pixel_count(): " + exception);
		return 0;
	}
}

/**
 * Retrieve the number which is enclosed inside the HTML span element whose id is "blue_pixel_count_span" on the corresponding web page.
 * 
 * Assume that the number of blue pixels is a nonnnegative integer no larger than 3600.
 * 
 * @return {Number} an integer representing the total number of blue pixel-sized "darts" which have been plotted on the HTML canvas element on the corresponding web page.
 */
function get_blue_pixel_count() {
	let blue_pixel_count_span = undefined, blue_pixel_count = 0;
	try {
		blue_pixel_count_span = document.getElementById("blue_pixel_count_span");
		blue_pixel_count = parseInt(blue_pixel_count_span.innerHTML);
		if ((blue_pixel_count < 0) || (blue_pixel_count > 3600)) throw "blue_pixel_count must be an integer no smaller than 0 and no larger than 3600.";
		return blue_pixel_count;
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in get_blue_pixel_count(): " + exception);
		return 0;
	}
}

/**
 * Set the number which is enclosed inside the HTML span element whose id is "pi_approximation_span" to the result of the following computation:
 * 
 * (4 * (red_pixel_count / (red_pixel_count + blue_pixel_count)))
 * 
 * where red_pixel_count represents the total number of red pixel-sized "darts" which have been plotted on the HTML canvas and
 * where blue_pixel_count represents the total number of blue pixel-sized "darts" which have been plotted on the same HTML canvas
 * on the corresponding web page.
 * 
 * Assume that this function is called once per second of the 3600 timed simulation.
 */
function update_pi_approximation() {
	let pi_approximation_span = undefined, pi_approximation = 0, red_pixel_count = 0, blue_pixel_count = 0;
	try {
		red_pixel_count = get_red_pixel_count();
		blue_pixel_count = get_blue_pixel_count();
		pi_approximation_span = document.getElementById("pi_approximation_span");
		pi_approximation = (4 * (red_pixel_count / (red_pixel_count + blue_pixel_count)));
		pi_approximation_span.innerHTML = pi_approximation;
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in update_pi_approximation(): " + exception);
	}
}

/**
 * Retrieve the number which is enclosed inside of the HTML span element whose id is "seconds_remaining_span" on the corresponding web page.
 * 
 * @return {Number} an integer which is assumed to be no smaller than 0 and no larger than 3600.
 */
function get_seconds_remaining() {
	let seconds_remaining_span = undefined, seconds_remaining = 0;
	try {
		seconds_remaining_span = document.getElementById("seconds_remaining_span");
		seconds_remaining = parseInt(seconds_remaining_span.innerHTML);
		if ((seconds_remaining < 0) || (seconds_remaining > 3600)) throw "seconds_remaining must be an integer no smaller than 0 and no larger than 3600.";
		return seconds_remaining;
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in get_seconds_remaining(): " + exception);
	}
}

/**
 * Subtract one from the total number of seconds remaining (which is displayed inside the HTML span element whose id is "seconds_remaining_span" on the corresponding web page).
 * 
 * Assume that the number of seconds remaining is always an integer which is no smaller than 0 and no larger than 3600.
 */
function decrement_seconds_remaining() {
	let seconds_remaining_span = undefined, seconds_remaining = 0;
	try {
		seconds_remaining_span = document.getElementById("seconds_remaining_span");
		seconds_remaining = parseInt(seconds_remaining_span.innerHTML);
		if ((seconds_remaining < 0) || (seconds_remaining > 3600)) throw "seconds_remaining must be an integer no smaller than 0 and no larger than 3600.";
		seconds_remaining -= 1;
		seconds_remaining_span.innerHTML = seconds_remaining;
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in decrement_seconds_remaining(): " + exception);
		return 0;
	}
}

/**
 * Translate a coordinate pair from its Cartesian point representation to its HTML canvas coordinate pair.
 * 
 * The Cartesian point coordinates treat the center of the HTML canvas as the origin of the Cartesian plane (i.e. where the x-coordinate is 0 and where the y-coordinate is 0).
 * 
 * The HTML canvas (which is a square area whose side lengths are each 400 pixels) is formatted such that the upper left corner has an x-coordinate of 0 and a y-coordinate of 0. 
 * 
 * @param {Object} point is assumed to be an object with the following properties: 
 * 			{Number} x_coordinate is assumed to be an integer no smaller than -200 and no larger than 200.
 *      		{Number} y_coordinate is assumed to be an integer no smaller than -200 and no larger than 200.
 *
 * @return {Object} an object whose properties are as follows:
 *     			{Number} x is assumed to be an integer no smaller than 0 and no larger than 400.
 *   			{Number} y is assumed to be an integer no smaller than 0 and no larger than 400.
 */
function convert_point_to_pixel(point) {
	let pixel = { x : 0, y : 0 }; // initialize pixel to represent the top left corner of the HTML5 canvas.
	try {
		if (!is_point(point)) throw "point must be an object whose properties are as follows: { x_coordinate : integer in range [-200,200], y_coordinate : integer in range [-200,200] }.";
		pixel.x = point.x_coordinate + 200; 
		pixel.y = 200 - point.y_coordinate;
		return pixel;
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in convert_point_to_pixel(point): " + exception);
	}
}

/**
 * Convert a Cartesian planar point to its corresponding HTML canvas point and plot it on the 400-by-400 pixel canvas element on the corresponding web page.
 * 
 * If that pixel-sized "dart" is plotted within 200 pixels of the center of the square canvas, then color the "dart" red.
 * 
 * If that pixel-sized "dart" is plotted farther than 200 pixels away from the center of the square canvas, then color the "dart" blue.
 * 
 * @param {Object} point is assumed to be an object with the following properties: 
 * 			{Number} x_coordinate is assumed to be an integer no smaller than -200 and no larger than 200.
 *        		{Number} y_coordinate is assumed to be an integer no smaller than -200 and no larger than 200.
 */
function plot_point_on_html_canvas(point) {
	let canvas = undefined, context = undefined, pixel = {}, distance_from_origin = 0;
	try {
		if (!is_point(point)) point = { x_coordinate : 0, y_coordinate : 0 };
		distance_from_origin = compute_distance_between_two_planar_points(point, { x_coordinate : 0, y_coordinate : 0 });
		pixel = convert_point_to_pixel(point);
		canvas = document.getElementById("cartesian_plane");
		context =  canvas.getContext("2d");
		if (distance_from_origin > 200) { // outside of radius of circle inscribed inside of 400-pixel square canvas
			context.beginPath();
			context.rect(pixel.x, pixel.y, 1, 1); // 1 pixel has a width of 1 and a height of 1
			context.strokeStyle = "#0000ff"; // HTML color code for blue.
			context.stroke();
			increment_blue_pixel_count();
		}
		else if (distance_from_origin <= 200) { // inside of radius of circle inscribed inside of 400-pixel square canvas
			context.beginPath();
			context.rect(pixel.x, pixel.y, 1, 1); // 1 pixel has a width of 1 and a height of 1
			context.strokeStyle = "#ff0000"; // HTML color code for red.
			context.stroke();
			increment_red_pixel_count();
		}
		else {
			throw "the pixel appears to be neither red nor blue.";
		}
		update_pi_approximation();

	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in plot_point_on_html_canvas(point): " + exception);
	}
}

/**
 * Draw a line whose thickness is one pixel and whose color is black from the middle of the left edge of the HTML canvas to the middle of the right edge of that canvas.
 * 
 * Assume that the canvas is 400 pixels in length on all sides.
 */
function draw_horizontal_line_through_middle_of_canvas() {
	let canvas = undefined, context = undefined;
	try {
		canvas = document.getElementById("cartesian_plane");
		context = canvas.getContext("2d");
		context.strokeStyle = "#000000"; 
		context.lineWidth = 1;
		context.beginPath();
		context.moveTo(0, 200); // middle point of left square canvas edge
		context.lineTo(400, 200); // middle point of right square canvas edge
		context.stroke();
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in draw_horizontal_line_through_middle_of_canvas(): " + exception);
	}
}

/**
 * Draw a line whose thickness is one pixel and whose color is black from the middle of the top edge of the HTML canvas to the middle of the bottom edge of that canvas.
 * 
 * Assume that the canvas is 400 pixels in length on all sides.
 */
function draw_vertical_line_through_middle_of_canvas() {
    let canvas = undefined, context = undefined;
    try {
    	canvas = document.getElementById("cartesian_plane");
    	context = canvas.getContext("2d");
    	context.strokeStyle = "#000000"; 
    	context.lineWidth = 1;
    	context.beginPath();
    	context.moveTo(200, 0); // middle point of top square canvas edge
    	context.lineTo(200, 400); // middle point of bottom square canvas edge
    	context.stroke();
    }
    catch(exception) {
    	console.log("An exception to expected functioning occurred in draw_vertical_line_through_middle_of_canvas(): " + exception);   	
    }
}

/**
 * Remove any shapes which were plotted on the HTML canvas whose id is "cartesian_plane" on the corresponding web page.
 * 
 * Assume that this function is called in response to the RESET button being clicked.
 */
function clear_canvas() {
	let canvas = undefined, context = undefined;
	try {
		canvas = document.getElementById("cartesian_plane");
		context = canvas.getContext("2d");
		context.clearRect(0, 0, canvas.width, canvas.height);
		context.closePath();
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in clear_canvas(): " + exception);   	
	}
}

/**
 * Make the START button invisible as soon as it is clicked and for the duration of the 3600 timed Monte Carlo dart-throwing simulation.
 * 
 * Assume that this function is called in response to the START button being clicked.
 */
function hide_start_button() {
	try {
		let start_button = document.getElementById("start_button");
		start_button.style.display = "none";
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in hide_start_button(): " + exception);
	}
}

/**
 * Make the START button visible as soon as it is clicked and for the duration of the 3600 timed Monte Carlo dart-throwing simulation.
 * 
 * Assume that this function is called in response to the RESET button being clicked.
 */
function unhide_start_button() {
	try {
		let start_button = document.getElementById("start_button");
		start_button.style.display = "block";
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in unhide_start_button(): " + exception);
	}
}

/**
 * Make the RESET button invisible after the RESET button is clicked or after the web page is loaded by the web browser.
 */
function hide_reset_button() {
	try {
		let reset_button = document.getElementById("reset_button");
		reset_button.style.display = "none";
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in hide_reset_button(): " + exception);
	}
}

/**
 * Make the RESET button visible as soon as the 3600 timed Monte Carlo dart-throwing simulation finishes.
 */
function unhide_reset_button() {
	try {
		let reset_button = document.getElementById("reset_button");
		reset_button.style.display = "block";
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in unhide_reset_button(): " + exception);
	}
}

/**
 * Set the HTML canvas whose id is "cartesian_plane" to its initial state: no colored darts and two perpendicular axis intersecting at the center of the canvas.
 * 
 * Make the RESET button invisible (and therefore unclickable).
 * 
 * Make the START button visible (and therefore clickable).
 * 
 * Set the value enclosed by the span element whose id is "seconds_remaining_span" to 3600.
 * 
 * Set the value enclosed by the span element whose id is "red_pixel_count_span" to 0.
 * 
 * Set the value enclosed by the span element whose id is "blue_pixel_count_span" to 0.
 * 
 * Set the value enclosed by the span element whose id is "pi_approximation" to 0.
 */
function initialize_application() {
	const time_point = Date.now(), p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>';
	let seconds_remaining_span, red_pixel_count_span, blue_pixel_count_span, pi_approximation_span, timestamp, message, console_div;
	try {
		message = "The initialize_application() function was called at time: " + time_point + " milliseconds since 01_JANUARY_1970 00:00:00 (Coordinated Universal Time (UTC)).";
		console.log(message);
		hide_reset_button();
		unhide_start_button();
		clear_canvas();
		draw_horizontal_line_through_middle_of_canvas();
		draw_vertical_line_through_middle_of_canvas();
		seconds_remaining_span = document.getElementById("seconds_remaining_span");
		red_pixel_count_span = document.getElementById("red_pixel_count_span");
		blue_pixel_count_span = document.getElementById("blue_pixel_count_span");
		pi_approximation_span = document.getElementById("pi_approximation_span");
		console_div = document.getElementById("timestamped_events_log");
		seconds_remaining_span.innerHTML = 3600; 
		red_pixel_count_span.innerHTML = 0;
		blue_pixel_count_span.innerHTML = 0;
		pi_approximation_span.innerHTML = 0;
		console_div.innerHTML += p0 + message + p1;
	}
	catch(exception) {
		console.log("An exception to expected functioning occurred in initialize_page(): " + exception);
	}
}

/**
 * Print a time-stamped message to the web browser console which indicates that the timed simulation has finished.
 * 
 * Assume that this function is called in response to a timer interval session completing some finite number of 3600 iterations 
 * such that each iteration is temporally spaced by one second.
 * 
 * Assume that plot_random_pixel_on_square_canvas(simulation) is the function which is called 3600 times 
 * such that each plot_random_pixel_on_square_canvas(simulation) call is temporarlly spaced by one second.
 */
function finish_simulation() {
	const time_point = Date.now(), p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>';
	const message = "The Monte Carlo simulation ended at time: "  + time_point + " milliseconds since 01_JANUARY_1970 00:00:00 (Coordinated Universal Time (UTC)).";
	console.log(message);
	document.getElementById("timestamped_events_log").innerHTML += p0 + message + p1;
}

/**
 * Call plot_random_pixel_on_square_canvas(simulation) once per second until seconds_remaining is 0.
 * 
 * Each time plot_random_pixel_on_square_canvas(simulation) is called, decrement seconds_remaining by 1.
 * 
 * @param {Object} simulation is assumed to be a timer interval handler (as defined in the start_monte_carlo_simulation() function).
 */
function plot_random_pixel_on_square_canvas(simulation) {
	let point, seconds_remaining;
	point = generate_random_planar_point();
	decrement_seconds_remaining();
	seconds_remaining = get_seconds_remaining();
	plot_point_on_html_canvas(point);
	if (seconds_remaining === 0) {
		clearInterval(simulation); 
		unhide_reset_button();
		finish_simulation();
	}
}

/**
 * Begin the 3600 second Monte Carlo dart throwing simulation.
 * 
 * Assume that this function is called in response to the START button being clicked.
 * 
 * Throw one random pixel-sized dart onto the square canvas per second for a total of 3600 seconds.
 * 
 * Use the setInterval function to space plot_random_pixel_on_square_canvas(simulation) function calls apart by one second.
 */
function start_monte_carlo_simulation() {
	const time_point = Date.now(), p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>';
	let simulation; // timer interval handler
	const message = "The Monte Carlo simulation started at time: " + time_point + " milliseconds since 01_JANUARY_1970 00:00:00 (Coordinated Universal Time (UTC)).";
	console.log(message);
	document.getElementById("timestamped_events_log").innerHTML += p0 + message + p1;
	initialize_application();
	hide_start_button();
	simulation = setInterval( function() { plot_random_pixel_on_square_canvas(simulation); }, 1000); // The plot_random_pixel_on_square_canvas(simulation) function is called once every 1000 milliseconds until the timer interval is cleared.
}
