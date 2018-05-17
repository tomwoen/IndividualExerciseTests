Update_Account()
{

	web_add_auto_header("DNT", 
		"1");

	web_url("success.txt", 
		"URL=http://detectportal.firefox.com/success.txt", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t10.inf", 
		LAST);

	web_url("success.txt_2", 
		"URL=http://detectportal.firefox.com/success.txt", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t11.inf", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(6);

	web_url("json", 
		"URL=http://localhost:8080/accountapp/api/accounts/json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://localhost:8080/accountapp/updateaccountpage.html", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=http://detectportal.firefox.com/success.txt", "Referer=", ENDITEM, 
		LAST);

	web_add_auto_header("DNT", 
		"1");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(27);

	web_custom_request("1", 
		"URL=http://localhost:8080/accountapp/api/accounts/json/1", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://localhost:8080/accountapp/updateaccountpage.html", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body={\"ID\":\"1\",\"firstName\":\"Thomas\",\"lastName\":\"Owen\",\"accountNumber\":\"1234\"}", 
		LAST);

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("updateaccountpage.html", 
		"URL=http://localhost:8080/accountapp/updateaccountpage.html", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=addpage.css", ENDITEM, 
		"Url=js/jQuery/jquery-3.3.1.js", ENDITEM, 
		"Url=js/main.js", ENDITEM, 
		"Url=js/updateaccount.js", ENDITEM, 
		"Url=js/delete.js", ENDITEM, 
		LAST);

	web_reg_find("Text=Thomas", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("json_3", 
		"URL=http://localhost:8080/accountapp/api/accounts/json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://localhost:8080/accountapp/updateaccountpage.html", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(10);

	web_custom_request("1_2", 
		"URL=http://localhost:8080/accountapp/api/accounts/json/1", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://localhost:8080/accountapp/updateaccountpage.html", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body={\"ID\":\"1\",\"firstName\":\"Paul\",\"lastName\":\"Owen\",\"accountNumber\":\"1234\"}", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("updateaccountpage.html_2", 
		"URL=http://localhost:8080/accountapp/updateaccountpage.html", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t18.inf", 
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

	web_url("json_4", 
		"URL=http://localhost:8080/accountapp/api/accounts/json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://localhost:8080/accountapp/updateaccountpage.html", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}