// xiejian.c а������
#include <ansi.h>
inherit NPC;
int waiting(object me);
int checking(object me);
int do_chase(object me);
int do_kill(object me, object dest);
string ask_me();
void create()
{
    set_name("����", ({ "li si", "li" }) );
    set("title", "С���ϰ�");
    set("gender", "����" );
    set("shen_type", -1);
    set("age", 40);
    set("str", 30);
    set("con", 30);
    set("int", 30);
    set("dex", 30);
	set("no_put", 1);
    set("no_clean_up",1);
    set("long",
        "��������Ц�����С���ϰ壬��Ȼ����ʲ�ᶫ����ȴҲ�������ڡ�\n" );
    set("combat_exp", 50000);
    set("attitude", "peaceful");
    set("chat_chance", 1);
    set("chat_msg", ({
        "����˵��: ��λ�͹٣�������Щʲ�ᶫ���� ?\n",
    }) );
    set("inquiry", ([
            "а��"   : (: ask_me :),
            "ɱ��"   : (: ask_me :),
    ]) );
    set("max_neili", 3000);
    set("jiali", 50);
    set("shen_type", -1);
    set_skill("force", 60); 
    set_skill("unarmed", 80);
    set_skill("sword", 100);
    set_skill("dodge", 100);
    set_skill("parry", 100);
    
    setup();
    
    carry_object("clone/weapon/changjian")->wield();
    carry_object("clone/cloth/cloth")->wear();
}
void init()
{
    object me, ob;
    me = this_object();
    ob = this_player();
        ::init();
    if( !me->query("waiting_target") && ob->query_temp("fee_paid") ) 
        ob->delete_temp("fee_paid");
        add_action("do_name","ɱ");
    
}
string ask_me()
{
    return "�Ҿ���а�����ģ�����������ʲ������\n";
}
int do_name(string target)
{
    object me, dest, *all,ob;
    int i;
 
    me = this_object();
    all = users();
    if(me->query("waiting_target"))
        return notify_fail("���ĺٺ�һЦ����������æ���ģ�������������ɣ�\n");
    
    if( !this_player()->query_temp("fee_paid") ) 
        return notify_fail("����˵�������ܽ�����ʲ�ᣬ���ɵ��ȸ�Ǯ�ģ�\n");
   if (base_name(environment())!=query("startroom")){
        return notify_fail("����˵����������������˵��̫�׵��ɣ�\n");
     }
       if( this_player()->query("age")<19 ) 
        return notify_fail("����˵��������С����û׼����ˣ�ң���ȥ��\n");
    if( !target || target==" ") 
        return notify_fail("���Ķ�ݺݵ�˵������������Ǽһ�����֣��ҿ�û�����������ģ�\n");
    for(i=0; i<sizeof(all); i++) 
    {
        if( target == all[i]->name() || all[i]->id(target) )
            dest = all[i];
    }
    
    if( !dest )
        return notify_fail("����һ����Ц�������ڲ�����Ϸ�У����������ɡ�\n");
        
    if (dest->is_ghost())
        return notify_fail("���ĺܲ����ˣ����Ѿ��Ǹ������ˣ��㻹�����Ҹ�ʲô��\n");
    me->set("waiting_target", dest->query("id"));
	ob=this_player();
    if ((ob->query_temp("pker_starttime")+900*ob->query_temp("pker_time")) <ob->query("mud_age")){
                ob->set_temp("pker_starttime",ob->query("mud_age"));
		ob->delete_temp("pker_time");
	}
    ob->add_temp("pker_time",1);
    me->set_temp("apply/attack",  50);
    me->set_temp("apply/defense", 50);
    me->set_temp("apply/damage",  20);
    me->set("title", HIB "а��" NOR);
	
    me->set("long",
        "а�����ģ�ɱ�ְ�ʮ��߼���ʿ֮һ���н���ȾѪ������֮����\n" );
    me->delete("chat_chance");
    me->delete("chat_msg");
    message("vision",
        HIY "���ĺٺٺٵظ�Ц�˼�����˵����������������������!\n"NOR,
        environment(), me );
    me->set("pursuer", 1);
    me->set("vendetta/authority", 1);
    me->set("combat_exp", 50000);
    message_vision("$N���˳�ȥ��\n" NOR, me);
    CHANNEL_D->do_channel(me,"sys",sprintf("%s��Ӷ����ɱ%s",this_player()->query("name"),dest->query("name")));
    ob=new(__DIR__"obj/paper");
       ob->set("long",sprintf("��򿪲�ֽһ���������ּ�ģ����д�ţ�\nXX%sXXXXX��Ӷ***��XXɱX**%sXXXXXX\n\n\n",this_player()->query("name"),dest->query("name")));
    ob->move(this_object());
    call_out("do_chase", 1, me);
    
    return 1;
}
int accept_object(object who, object ob)
{
         int i;
        if (ob->query("money_id") && ob->value() >= 10000
        && !this_object()->query("waiting_target")) 
    {
                                i=ob->value()/10000;
                                i=i<10 ? 10 : i ;
        if (i>2500) i=2500;
		if (who->query("age")<19){
		   tell_object(who,"���İ�ǮС���պã�Ц������˵��С����������������������Ǻ�«����ͷ\n�ǰ��ɵ��������Ǯ�ˣ�������˵�����պ�����Ա��Ǻ�«�ˣ���֤������\n.....һ���ӣ�\n");
		   return 1;
		}
        tell_object(who, "���ĳ����������ã�ˬ��˵�ɣ���Ҫ�Ұ���ɱ˭��\n");
        tell_object(who, "����룺ɱ Ŀ��\n");
        who->set_temp("fee_paid",1);
        set_skill("force", i ); 
        set_skill("unarmed", i ); 
        set_skill("parry", i ); 
        set_skill("dodge", i ); 
        set_skill("sword", i ); 
         set("combat_exp",(i*i/10)*i);
        return 1;
    }
    else if (ob->query("money_id") && ob->value() < 10000) 
    {
        tell_object(who, "���ĺٺ�һЦ��˵�������������Ǯ�� �����ҿ�û�����㰡��\n");
        return 1;
    }
    return 0;
}
int do_chase(object me)
{
    
    object dest;
    mapping exits;
    dest = find_player(me->query("waiting_target"));
    
    if( !objectp(dest) || !environment(dest) )  
    {
        call_out("waiting", 0, me);
        return 1;
    }
    exits=environment(dest)->query("exits");
    if (!mapp(exits) || !sizeof(exits) )
    {
        call_out("waiting", 0, me);
        return 1;
    }
    
    me->move(environment(dest));
    message_vision("$N���˹�����\n" NOR, me);
    me->set_leader(dest);
    command("look " + dest->query("id"));
    
    if ( !environment(me)->query("no_fight"))
    {
        call_out("do_kill", 1, me, dest);
        return 1;
    }
    else
    {
        call_out("waiting", 0, me);
        return 1;
    }
    return 1;
}
int do_kill(object me, object dest)
{
    if( objectp(dest) && present(dest, environment(me))
         && !environment(me)->query("no_fight"))
    {
        message_vision(HIR "$N��$n˵������˾����������������ȥ���Ƕ����ͣ�"
            +RANK_D->query_rude(dest)+"���������ɣ�\n" NOR, me, dest);
        me->set_leader(dest);
        me->kill_ob(dest);
        dest->fight_ob(me);
        call_out("checking", 0,  me);   
    }
    else  
        call_out("waiting", 1, me);     
    
    return 1;
}
int waiting(object me)
{
    object dest;
    dest = find_player(me->query("waiting_target"));
    
    if ( objectp(dest) )
    {
        if (dest->is_ghost())
        {
            me->delete("waiting_target");
            call_out("do_back", 1, me);
            return 1;
        }else if (me->is_fighting() && present(dest, environment(me)))
        {
            call_out("checking", 0, me);
            return 1;
        }else if (living(me) && !environment(dest)->query("no_fight"))
        {
            call_out("do_chase", 0, me);
            return 1;
        }
    }       
    
    remove_call_out("waiting");
    call_out("waiting", 60, me);
    return 1;
}
int checking(object me)
{
    if (me->is_fighting()) 
    {
        call_out("checking", 1, me);
        return 1;
    }
    if( present("corpse", environment(me)) )    
    {
        me->delete("waiting_target");
        call_out("do_back", 1, me);
        return 1;
    }
    
    call_out("waiting", 0, me);
    return 1;
}
int do_back(object me)
{
    me->move("/d/village/shop");
    message("vision", "�������˽��������������ϵĳ������ѽ��ϵ�Ѫ��Ĩ�øɾ���\n"
        "������һЦ˵��������ү���ӣ�����ɵøɾ����䣬����������ʲ���»��������ҡ�\n", 
        environment(), me );
    me->set("title", "С���ϰ�");
    me->set("long",
        "��������Ц�����С���ϰ壬��Ȼ����ʲ�ᶫ����ȴҲ�������ڡ�\n" );
    command("drop paper");
    me->set_leader(0);
    me->set("chat_chance", 1);
    me->set("chat_msg", ({
        "����˵��: ��λ�͹٣�������Щʲ�ᶫ���� ?\n",
    }) );
    return 1;
}
