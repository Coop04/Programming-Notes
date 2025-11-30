<?php
// Day Notations
// d  = Day of month (01–31)
// j  = Day of month without leading zero (1–31)
// D  = Short day name (Mon, Tue, Wed)
// l  = Full day name (Monday, Tuesday)
// N  = ISO day number (1 = Monday, 7 = Sunday)

// Month Notations
// m  = Month (01–12)
// n  = Month without leading zero (1–12)
// M  = Short month name (Jan, Feb, Mar)
// F  = Full month name (January, February)

// Year Notations
// Y  = Full year (2025)
// y  = Short year (25)

// Time Notations
// H  = 24-hour format (00–23)
// h  = 12-hour format (01–12)
// i  = Minutes (00–59)
// s  = Seconds (00–59)
// a  = am/pm
// A  = AM/PM

// Full Date-Time Examples
// Y-m-d         = 2025-11-16
// d/m/Y         = 16/11/2025
// l, d F Y      = Sunday, 16 November 2025
// Y-m-d H:i:s   = 2025-11-16 18:21:55

$date1 = date("d/m/Y");

echo $date1;
// -------------------------------
echo "<br>";
$date = date("l");

switch($date) {
    case "Monday":
        echo "I hate Mondays";
        break;

    case "Tuesday":
        echo "It is Taco Tuesday!";
        break;

    case "Wednesday":
        echo "The work week is half over!";
        break;

    case "Thursday":
        echo "It's almost the weekend!";
        break;

    case "Friday":
        echo "TGIF!";
        break;

    case "Saturday":
        echo "It's the weekend!";
        break;

    case "Sunday":
        echo "Relax, it's Sunday!";
        break;

    default:
        echo "Invalid day";
        break;
}
?>

