// suicide.c

#include <ansi.h>
// inherit F_CLEAN_UP;
int id_temp; string id_num;
int main(object me, string arg)
{
	if( me->is_busy() )
		return notify_fail("����һ��������û��ɡ�\n");
	if( !arg ) {
		write("��ɱ�����Ҫ�����Ӵ��\n");
		return 1;
	}
	if( arg!="-f" ) 
		return notify_fail("��ɱ�����Ҫ�����Ӵ��\n");
	if (SECURITY_D->get_status(me)!="(player)")
             return notify_fail("�����Ҫ��������ʦ���㽵����Ҳ�����ɱ!\n");
	write(
		"�����ѡ����Զ��������ɱ��ʽ�������������Ͼ���Զɾ���ˣ������\n"
"���������ȷ���Ļ�������������ݱ�ʶ��");	
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
write("��ݱ�ʶ����\n");	
		return;
	}
	if (forever) {
		tell_object( me,
		HIR "\n\n�����Ҫ��ɱ�ˣ������ʮ���ڲ���ڣ�����������ˡ�\n\n\n" NOR);

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
		tell_object(me, RED "\n\n\n�㻹��"+YEL+chinese_number(sec)+"��"+RED+"��ʱ�������ڡ�\t\t"+HIW+"���������ˣ��������˳�(quit)��Ϸ��\n\n\n" NOR);
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
		msg = "���"+(me->query("gender")=="Ů��"?"����":"�Ϲ�")+"��ɱ�������Զ������\n";
		mail = ([
			"from": "��������",
			"title": "�����Լ",
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
		write("�ðɣ�������:)��\n");


	tell_room(environment(me), me->name() +"��ɱ�ˣ���������Ҳ������������ˡ�\n", ({me}));	
	CHANNEL_D->do_channel(environment(me),"rumor", me->name() +"��ɱ�ˣ���������Ҳ������������ˡ�\n", ({me}));	
	me->set_temp("no_end_save", 1);
	destruct(link_ob);
	destruct(me);
	return 0;
}
int help (object me)
{
        write(@HELP
ָ���ʽ: suicide -f
 
�����Ϊĳ��ԭ���㲻�����, �����ѡ����ɱ��
 
suicide -f : ��Զ�ĳ�ȥ�������, ϵͳ��Ҫ����
             ����������ȷ����ݡ�
 
������ѡ�� :)
 
HELP
);
        return 1;
}
