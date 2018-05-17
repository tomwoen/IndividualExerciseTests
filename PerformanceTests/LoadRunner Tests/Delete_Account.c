Delete_Account()
{

	web_add_auto_header("DNT", 
		"1");

	web_url("success.txt", 
		"URL=http://detectportal.firefox.com/success.txt", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t16.inf", 
		LAST);

	web_url("success.txt_2", 
		"URL=http://detectportal.firefox.com/success.txt", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t17.inf", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	lr_think_time(7);

	web_url("success.txt_3", 
		"URL=http://detectportal.firefox.com/success.txt", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t18.inf", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("json", 
		"URL=http://localhost:8080/accountapp/api/accounts/json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://localhost:8080/accountapp/addaccountpage.html", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	/* ---- Go to Update Pagee ---- */
	
	lr_start_transaction("Get To Update Page");


	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(9);

	web_url("updateaccountpage.html", 
		"URL=http://localhost:8080/accountapp/updateaccountpage.html", 
		"Resource=0", 
		"Referer=http://localhost:8080/accountapp/addaccountpage.html", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("json_2", 
		"URL=http://localhost:8080/accountapp/api/accounts/json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://localhost:8080/accountapp/updateaccountpage.html", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("Get To Update Page", LR_AUTO);


	/* ---- Enter Details and Delete ---- */

	lr_think_time(28);
	
	lr_start_transaction("Delete");

	web_custom_request("1", 
		"URL=http://localhost:8080/accountapp/api/accounts/json/{ID_Number}", 
		"Method=DELETE", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://localhost:8080/accountapp/updateaccountpage.html", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		"Body={\"ID\":\"1\",\"firstName\":\"Tom\",\"lastName\":\"Owen\",\"accountNumber\":\"1235\"}",
		LAST);
	
	lr_end_transaction("Delete", LR_AUTO);


	/* ---- Remove Alert ---- */
	
	web_revert_auto_header("X-Requested-With");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(16);
	
	web_url("updateaccountpage.html_2", 
		"URL=http://localhost:8080/accountapp/updateaccountpage.html", 
		"Resource=0", 
		"Referer=http://localhost:8080/accountapp/addaccountpage.html", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=addpage.css", ENDITEM, 
		"Url=js/jQuery/jquery-3.3.1.js", ENDITEM, 
		"Url=js/main.js", ENDITEM, 
		"Url=js/updateaccount.js", ENDITEM, 
		"Url=js/delete.js", ENDITEM, 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("json_3", 
		"URL=http://localhost:8080/accountapp/api/accounts/json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://localhost:8080/accountapp/updateaccountpage.html", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}