// suicide.c

#include <ansi.h>
// inherit F_CLEAN_UP;
int id_temp; string id_num;
int main(object me, string arg)
{
	if( me->is_busy() )
		return notify_fail("你上一个动作还没完成。\n");
	if( !arg ) {
		write("自杀？你可要想清楚哟！\n");
		return 1;
	}
	if( arg!="-f" ) 
		return notify_fail("自杀？你可要想清楚哟！\n");
	if (SECURITY_D->get_status(me)!="(player)")
             return notify_fail("你必须要由其他巫师把你降成玩家才能自杀!\n");
	write(
		"如果您选择永远死掉的自杀方式，这个人物的资料就永远删除了，请务必\n"
"考虑清楚，确定的话请输入您的身份标识：");	
input_to("check_biaoshi", 1, me, 1);	
	return 1;
}
protected void check_biaoshi(string biaoshi, object me, int forever)   	
{
	object link_ob;
string old_biaoshi;	
	link_ob = me->query_temp("link_ob");
old_biaoshi = link_ob->query("biaoshiold");	
if( crypt(biaoshi, old_biaoshi)!=old_biaoshi ) {	
write("身份标识错误！\n");	
		return;
	}
	if (forever) {
		tell_object( me,
		HIR "\n\n你决定要自杀了，如果四十秒内不後悔，就真的永别了。\n\n\n" NOR);

		me->start_busy(30);
		me->set_temp("suicide",1);
		call_out("slow_suicide",5,me,40);
	}
}
protected int slow_suicide(object me,int sec)
{
	if (!me)	return 0;
	sec-=5;
	if (sec>1){
		tell_object(me, RED "\n\n\n你还有"+YEL+chinese_number(sec)+"秒"+RED+"的时间可以後悔。\t\t"+HIW+"如果你後悔了，请马上退出(quit)游戏。\n\n\n" NOR);
		call_out("slow_suicide",5,me,sec);
	}else	call_out("do_suicide",1,me);
	return 1;
}
int do_suicide(object me)
{
        mapping mail;
        string id,mailfile, cid,msg;
	object link_ob,couple,mbx;
	if (!me)	return 0;
	link_ob = me->query_temp("link_ob");
	if( !link_ob ) return 0;
	log_file("static/SUICIDE",
		sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );
       id=me->query("id");
        seteuid(getuid());
//  to unmarry the player when his/her partener suicide -f
// program below do not get time to test, shall there be any bug, please let me know.  
	if(mapp(me->query("couple")))
	{
        cid = me->query("couple/couple_id");
        couple = find_player(cid);
		msg = "你的"+(me->query("gender")=="女性"?"妻子":"老公")+"自杀，婚姻自动解除。\n";
		mail = ([
			"from": "月下老人",
			"title": "解除婚约",
			"to": cid,
			"time": time(),
			"status": "N",
			"text": msg
			]);
       if(couple) 
	   {
			mbx = new(MAILBOX_OB);
			mbx->set_owner(cid);
			mbx->send_mail(cid,mail);
			couple->delete("couple");
		}
	}
	rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
	rm( me->query_save_file() + __SAVE_EXTENSION__ );	
    mailfile=sprintf(DATA_DIR "mail/%c/%s", id[0], id);
    rm (mailfile+ __SAVE_EXTENSION__ );
	delete_item_data(me);
	me->set_temp("no_auto_items", 1);
	id_num=read_file("/adm/daemons/iduser",1);
                id_temp=atoi(id_num); id_temp=id_temp-1;
                id_num=sprintf("%d",id_temp);
                write_file("/adm/daemons/iduser",id_num,1);
		write("好吧，永别了:)。\n");


	tell_room(environment(me), me->name() +"自杀了，以後你再也看不到这个人了。\n", ({me}));	
	CHANNEL_D->do_channel(environment(me),"rumor", me->name() +"自杀了，以後你再也看不到这个人了。\n", ({me}));	
	me->set_temp("no_end_save", 1);
	destruct(link_ob);
	destruct(me);
	return 0;
}
int help (object me)
{
        write(@HELP
指令格式: suicide -f
 
如果因为某种原因你不想活了, 你可以选择自杀。
 
suicide -f : 永远的除去玩家资料, 系统会要求你
             输入密码以确认身份。
 
请慎重选择 :)
 
HELP
);
        return 1;
}
