Add_Account()
{

	web_add_auto_header("DNT", 
		"1");

	web_url("success.txt", 
		"URL=http://detectportal.firefox.com/success.txt", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t20.inf", 
		LAST);

	lr_start_transaction("Opening AddAccountPage");

	
	web_url("success.txt_2", 
		"URL=http://detectportal.firefox.com/success.txt", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t21.inf", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(4);

	web_url("json", 
		"URL=http://localhost:8080/accountapp/api/accounts/json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://localhost:8080/accountapp/addaccountpage.html", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=http://detectportal.firefox.com/success.txt", "Referer=", ENDITEM, 
		LAST);
	
	lr_end_transaction("Opening AddAccountPage", LR_AUTO);


	/* ----- Add Account ----- */

	lr_think_time(17);

	lr_start_transaction("Add Account");

	
	web_custom_request("json_2", 
		"URL=http://localhost:8080/accountapp/api/accounts/json", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://localhost:8080/accountapp/addaccountpage.html", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body={\"firstName\":\"Tom\",\"lastName\":\"Owen\",\"accountNumber\":\"1235\"}", 
		LAST);
	
	lr_end_transaction("Add Account", LR_AUTO);


	/* -----Deal With Alert ----- */

	web_revert_auto_header("X-Requested-With");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(14);

	web_url("addaccountpage.html", 
		"URL=http://localhost:8080/accountapp/addaccountpage.html", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=addpage.css", ENDITEM, 
		"Url=js/jQuery/jquery-3.3.1.js", ENDITEM, 
		"Url=js/main.js", ENDITEM, 
		"Url=js/addnewaccount.js", ENDITEM, 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("json_3", 
		"URL=http://localhost:8080/accountapp/api/accounts/json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://localhost:8080/accountapp/addaccountpage.html", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}