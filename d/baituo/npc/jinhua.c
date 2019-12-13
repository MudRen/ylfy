// jinhua.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("��", ({ "jin hua","hua","jin"}) );
	set("gender", "Ů��" );
	set("age", 24);
	set("long", "һ������ò���Ĺ��\n");
	set("shen_type", 1);
	set("combat_exp", 800);
	set("str", 18);
	set("dex", 18);
	set("con", 18);
	set("int", 18);
	set("attitude", "friendly");
	set("chat_chance",20);
	set("chat_msg",({
	    "�𻨿����ţ��ҵ�����ô��ô��Ӵ��\n",
	    "��Ĩ�����᣺��ѽ���Һ�����ѽ��\n",
	    "��̾����˵������֪���������ܷ��ټ��������\n"
	   }) );
       set("inquiry",([
	   "����" : "���������۾�����֪������������������������ҿ�����\n",
	   "�廨Ь" : "�𻨳Ծ��ؿ����㣺�������廨Ь�𣿿���ҿ�����\n",
	   ]) );
       setup();
}
void init()
{
        object ob,me,room;
	ob = this_player();
        me = this_object();
	::init();
    if (!stringp(me->query("startroom"))) return;
	if (! room=find_object(me->query("startroom")))
		room=load_object(me->query("startroom"));
	if (room==environment())
	if( interactive(ob) && !is_fighting() )
	       {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say("��һ�����˽�����æ˵����λ" + RANK_D->query_respect(ob)
	  +"�������ǡ�����ɽׯ������Ӷ�ˡ������������Ϣ��\n");
}
int accept_object(object who, object ob)
{
        object obn,me,room;
    me=this_object();
	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("��û�����������\n");
       if (! room=find_object(me->query("startroom")))
               room=load_object(me->query("startroom"));
       if (room!=environment())
        return notify_fail("��Ц��Ц�����Ѿ������վ����Ѿ��ҵ������ˣ�\n");
	if (  (string)ob->query("name") != "�廨Ь")
		    return notify_fail("�𻨲���Ҫ���������\n");
       write( HIY "��˫�������廨Ь���������£�\n
       ��������ڣ���������Ů�������һ���Ϊ�����أ�\n" NOR );
     if(who->query_temp("��")<13) 
         { write("�𻨲��˲����ᣬ���һ����˵�������ɽ��δ����������γ�ȥѽ��\n"  ); return 1; }
       else if (who->query("combat_exp")<10000)
          { command("look "+who->query("id")); write("��˵��:�������ҵ�һ�����и��ˣ��β��������棿��СŮ�ӵ�����л��\n"); return 1;}
	if (!who->query("marks/��")){
	message_vision("��Ĩ�˰����ᣬ������˼ЦЦ˵����λ"
		+RANK_D->query_respect(who)+"��Ц�ˡ�\n
	    	��Ҳûʲô���������㣬��ֻ֪��ɽ��ͷ�и�Ǯ����ڴ��¡�\n
	    	����͸���������\n",who);
       	message_vision("$N��𻨴Ӵ��°����һֻǮ�䣬$N�Ȳ������ش�һ����\n
	 	�ۣ������ö�ö�Ľ���Ӵ��$N���������ذѽ���ȫװ���·��\n
		 ��֪����̫�����·��ų�������ӣ�����һ�Կ���ֱ�֣�\n
		 $N����ô��Ȼ��ɦɦͷ��Ҳ���š��ٺ١�ɵЦ��\n", who);
		obn = new("/clone/money/gold");
		obn->set_amount(100);
		obn->move(who);
		who->set("marks/��",1);
	}
      return 1;
}
