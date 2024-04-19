<php

// KMPSubstringSearch
// Given a string s and a pattern p, determine if the pattern exists in the string. Return the index of where the first occurrence starts
// https://www.youtube.com/watch?v=BXCEFAzhxGY

function substringMatch( $string, $pattern ) {
    

    $sizeS = strlen($string);
    $sizeP = strlen($pattern);
   
    $suffix = [0];
    // Generate prefix-suffix array
    $i=0;
    while( $i < $sizeP ) {
        for( $j=1; $j < $sizeP; $j++ ) {
            if( $pattern[$j] != $pattern[$i] ) {
                $suffix[$j] = 0;
                $i = 0;
            }
            else {
                $suffix[$j] = $suffix[$j-1] + 1;
                $i++;
            }
        }
        break;
    }
    
    $i = $j = 0;
    $matchIndex = null;
    while( $i < $sizeS ) {
        while( $j < $sizeP ) {
            if( $string[$i] == $pattern[$j] ) {
                if( $matchIndex == null )
                    $matchIndex = $i;
                $i++;
                $j++;
            } else {
                $j = $suffix[$j];
                $i++;
                $matchIndex = null;
            }
        }
    }

    return $matchIndex;
}
 

echo substringMatch('abcdsgwadsgzdsz','dsgwadsgzdsz');
