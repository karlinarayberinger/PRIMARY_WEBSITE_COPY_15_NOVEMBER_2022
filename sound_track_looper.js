/**
 * file: sound_track_looper.js
 * type: JavaScript
 * author: Karlina Ray Beringer
 * date: 12_NOVEMBER_2022
 * license: PUBLIC_DOMAIN
 */

/**
 * Get the Number of milliseconds which have elapsed since the Unix Epoch.
 * The Unix Epoch is 01_JANUARY_1970 at midnight (Coordinated Universal Time (UTC)).
 * @return {String} message displaying the time at which this function was called.
 */
function generate_time_stamp() {
 	const milliseconds_elapsed_since_unix_epoch = Date.now();
 	return  milliseconds_elapsed_since_unix_epoch + " milliseconds since midnight on 01_JANUARY_1970.";
}

/**
 * Generate an HTML formatted string which represents the list of options displayed by a select menu.
 * By clicking on the select element, an scrollable list of options will appear.
 * @return {String} a natural number of options for a select menu.
 */
function get_menu_options() {
	let HTML_string = ('<' + 'option value="frogs_croaking_24_august_2021.mp3" selected' + '>' + 'frogs_croaking_24_august_2021.mp3' + '<' + '/' + 'option' + '>');
	HTML_string += ('<' + 'option value="drumz_karbytes_10_july_2022.mp3"' + '>' + 'drumz_karbytes_10_july_2022.mp3' + '<' + '/' + 'option' + '>');
	HTML_string += ('<' + 'option value="drumz_karbytes_12_november_2022.mp3"' + '>' + 'drumz_karbytes_12_november_2022.mp3' + '<' + '/' + 'option' + '>');
	return HTML_string;
}

/**
 * Return the value of the selected menu OPTION of a SELECT menu element.
 * @param {String} select_menu_identifier is the id of a select HTML element.
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
	catch(e) {
		console.log("An exception to normal functioning occurred during the runtime of get_selected_menu_option(select_menu_identifier): " + e);
	}
}

/**
 * Assume that this function is called whenever the web page file is opened or refreshed by the web browser.
 * Display a time-stamped message which indicates the time at which the web page was opened as green text at the bottom of the page.
 * Set the cyan span text which represents seconds elapsed to the value 0.
 * Set the cyan span text which represents loops completed to the value 0.
 * Populate the sound file menu with multiple sound file options.
 * Set the yellow span text which represents loops completed to the one and only default selected value in the select menu.
 * Set the button to be visible rather than hidden to the application end user.
 * If a runtime error occurs, use the try-catch block to perform exception handling by displaying a relevant web console message.
 */
function load_web_page() {
	try {
		let message = "The web page was loaded by the web browser at time: " + generate_time_stamp();
		document.getElementById("console_display").innerHTML = message;
		document.getElementById("seconds_elapsed_display").innerHTML = "0";
		document.getElementById("loops_completed_display").innerHTML = "0";
		document.getElementById("sound_file_menu").innerHTML = get_menu_options();
		document.getElementById("file_selected_display").innerHTML = get_selected_menu_option_value("sound_file_menu");
		document.getElementById("the_button").style.display = "block";
	}
	catch(e) {
		console.log("An exception to normal functioning occurred during the runtime of load_web_page(): " + e);
	}
}

/**
 * Assume that this funciton is called by the event of a single button click (of the button whose id is "the_button").
 * Hide "the button" from the user interface after it is presumably clicked.
 * Display a time-stamped message which indicates the time at which the button was clicked as green text at the bottom of the page.
 * Set the cyan span text which represents seconds elapsed to the value 0.
 * Set the cyan  span text which represents loops completed to the value 0.
 * Start playing the selected sound file for an indefinite number of times and incrementing the number of seconds elapsed and the number of audio loops played.
 * If a runtime error occurs, use the try-catch block to perform exception handling by displaying a relevant web console message.
 */
function start_sound_track_looper() {
	try {
		let message = "The button was clicked at time: " + generate_time_stamp();
		let elapsed_seconds_display = document.getElementById("seconds_elapsed_display");
		let loops_completed_display = document.getElementById("loops_completed_display");
		let file_selected_display = document.getElementById("file_selected_display");
		let selected_file_name = get_selected_menu_option_value("sound_file_menu");
		let button = document.getElementById("the_button");
		let audio_file = undefined;
		let loop_length = undefined;
		let action = undefined;
		let number_of_seconds = 0;
		let number_of_loops = 0;
		document.getElementById("console_display").innerHTML += (('<' + 'p' + '>') + message + ('<' + '/' + '>'));
		button.style.display = "none";
		elapsed_seconds_display.innerHTML = "0";
		loops_completed_display.innerHTML = "0";
		file_selected_display.innerHTML = selected_file_name;
		audio_file = new Audio(selected_file_name);
		loop_length = audio_file.duration;
		audio_file.play(); 
		action = setInterval( 
			function() { // Call the anonymous function once per every 1000 milliseconds.
				number_of_seconds = parseInt(elapsed_seconds_display.innerHTML);
				number_of_loops = parseInt(loops_completed_display.innerHTML);
				number_of_seconds += 1
				if (audio_file.ended) { 
					number_of_loops += 1;
					audio_file.play();
				}
				elapsed_seconds_display.innerHTML = number_of_seconds;
				loops_completed_display.innerHTML = number_of_loops;
			}, 1000 // milliseconds per interval
		);
	}
	catch(e) {
		console.log("An exception to normal functioning occurred during the runtime of start_sound_track_looper(): " + e);
	}
}
