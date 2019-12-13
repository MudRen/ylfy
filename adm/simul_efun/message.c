// message.c

varargs void message_vision(string msg, object me, object you)
{
        string my_gender, your_gender, my_name, your_name;
        string str1, str2, str3;

		// Add By Wenwu
        if ( !objectp(me) || !objectp(environment(me)) )
			return;

        my_name= me->name();
        my_gender = me->query("gender");

        if(!my_name || !my_gender) return; //mon 10/23/97
        
        str1 = replace_string(msg,  "$P", gender_self(my_gender));
        str1 = replace_string(str1, "$N", gender_self(my_gender));
        str3 = replace_string(msg,  "$P", my_name);
        str3 = replace_string(str3, "$N", my_name);
        if( you ) {
                your_name= you->name();
                your_gender= you->query("gender");
                str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
                str2 = replace_string(str2, "$p", gender_self(your_gender));
                str2 = replace_string(str2, "$N", my_name);
                str2 = replace_string(str2, "$n", gender_self(your_gender));
                message("vision", str2, you);
                str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
                str1 = replace_string(str1, "$n", your_name);
                str3 = replace_string(str3, "$p", your_name);
                str3 = replace_string(str3, "$n", your_name);
        }
        message("vision", str1, me);
        if(environment(me)) {
                if(you) 
                    message("vision", str3,  environment(me), ({ me, you}) );
                else
                    message("vision", str3,  environment(me), ({ me}));
        }
        if(environment(me)->query("fight_room"))
        environment(me)->relay_message(str3);
}

void tell_object(object ob, string str)
{
	if ( ob ) message("tell_object", str, ob);
}

varargs void tell_room(mixed ob, string str, object *exclude)
{
	if( ob ) message("tell_room", str, ob, exclude);
}

void shout(string str)
{
	message("shout", str, users(), this_player());
}

void write(string str)
{
	if ( this_player() )
		message("write", str, this_player());
	else if ( previous_object() )
		message("write", str, previous_object());
	else
		efun::write(str);
}

varargs void say(string str, mixed exclude)
{
	if( living(previous_object()) )
		message("say", str, environment(previous_object()), previous_object());
	else if( this_player() )
		message("say", str, environment(this_player()), this_player());
}

int notify_fail(string msg)
{
	object ob;
	if ( ob = this_player() ) 
	{
		if ( living(ob) )
		{
			message("notify_fail", msg, ob);
		}
		else return efun::notify_fail(ESC "[256D" ESC "[K" + msg);
	}
	else
		return 0;
}

varargs void printf (string msg, mixed a1, mixed a2, mixed a3, mixed a4,
         mixed a5, mixed a6, mixed a7, mixed a8, mixed a9, mixed a10,
         mixed a11, mixed a12, mixed a13, mixed a14, mixed a15, mixed a16)
{
    msg = sprintf (msg,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16);
    
    write (msg);
}

void message_system(string message)
{
	message("system", HIW "\n��ϵͳ��ʾ��" + message + "\n" NOR, users());
}