




/*
     FILE ARCHIVED ON 20:43:07 Oct 7, 2007 AND RETRIEVED FROM THE
     INTERNET ARCHIVE ON 12:41:29 Mar 21, 2015.
     JAVASCRIPT APPENDED BY WAYBACK MACHINE, COPYRIGHT INTERNET ARCHIVE.

     ALL OTHER CONTENT MAY ALSO BE PROTECTED BY COPYRIGHT (17 U.S.C.
     SECTION 108(a)(3)).
*/

function WriteIt() 
{
  document.write("<p>" + MyPageLoc + "</p>\n");
  document.write("<p>" + MyPageTitle + "</p>\n");
}

function BookmarkIt() 
{

document.write("<p><U><font size=2 face=\"Arial\">BOOKMARK THIS PAGE:</font></u><br>");

document.write("<font size=1 face=\"Arial\">|");

document.write("<a href=\"/web/20071007204307/http://digg.com/submit?phase=2&url=" + MyPageLoc + "&title=" + MyPageTitle + "&topic=general_sciences\">Digg this!</a>");
document.write("|");
document.write("<a href=\"/web/20071007204307/http://del.icio.us/post?url=" + MyPageLoc + "&title=" + MyPageTitle + "\">Del.icio.us</a>");
document.write("|");
document.write("<a href=\"/web/20071007204307/http://technorati.com/faves?add=" + MyPageLoc + "\">Technorati</a>");
document.write("|");
document.write("<a href=\"/web/20071007204307/http://reddit.com/submit?url=" + MyPageLoc + "&title=" + MyPageTitle + "\">Reddit</a>");
document.write("|");
document.write("<a href=\"/web/20071007204307/http://cgi.fark.com/cgi/fark/submit.pl?new_url=" + MyPageLoc + "&new_comment=" + MyPageTitle + "\">Fark</a>");
document.write("|");
document.write("<a href=\"/web/20071007204307/http://www.squidoo.com/lensmaster/bookmark?" + MyPageLoc + "&title=" + MyPageTitle + "\">Squidoo</a>");
document.write("|");
document.write("<a href=\"/web/20071007204307/http://furl.net/storeIt.jsp?t=" + MyPageTitle + "&u=" + MyPageLoc + "\">Furl</a>");
document.write("|");
document.write("<a href=\"/web/20071007204307/http://blinklist.com/index.php?Action=Blink/addblink.php&URL=" + MyPageLoc + "&Title=" + MyPageTitle + "\">Blinklist</a>");
document.write("|");
document.write("<a href=\"/web/20071007204307/http://myweb.yahoo.com/myresults/bookmarklet?u=" + MyPageLoc + "&t=" + MyPageTitle + "\">Yahoo MyWeb</a>");
document.write("|");
document.write("<a href=\"/web/20071007204307/http://www.google.com/bookmarks/mark?op=edit&bkmk=" + MyPageLoc + "&title=" + MyPageTitle + "\">Google</a>");
document.write("|");
document.write("<a href=\"/web/20071007204307/http://www.stumbleupon.com/submit?url=" + MyPageLoc + "&title=" + MyPageTitle + "\">Stumbleupon</a>");
document.write("|</font></p>\n");

}


function CiteThisPageAs()
{
document.write("<p><U><font size=2 face=\"Arial\">CITE THIS PAGE AS</font></u>:<br>\n");
document.write("<font size=1 face=\"Arial\">A. Bogomolny, <u>" + MyPageTitle + "</u> from <em>Interactive Mathematics Miscellany and Puzzles</em><br>\n");
document.write("<a href=\"" + MyPageLoc + "\">" + MyPageLoc + "</a>, Accessed " + StringDate());
document.write("</font></p>\n");
}


function StringDate() {
    var now = new Date();
    var months = new Array('January','February','March','April','May','June','July','August','September','October',                                  'November','December');
    var date = ((now.getDate()<10) ? "0" : "")+ now.getDate();
    return date + " " + months[now.getMonth()] + " " + fourdigityear(now.getYear());
}

function fourdigityear(number)	
{
  return (number < 1000) ? number + 1900 : number;
}


