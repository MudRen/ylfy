// xiaoer2.c �Ϻ�
inherit NPC;
inherit F_DEALER;
string ask_me();
int do_back(object me);
void create()
{
        set_name("�Ϻ�", ({ "lao he", "he", "xiao er", "waiter" }) );
        set("gender", "����" );
        set("age", 92);
        set("neili",100000);
      set("jing",5000);
      set("max_jing",5000);
        set("jiali",600);
        set("max_neili",10000);
        set("dex",180);
        set("str",100);
        set("long",
                "�Ϻ���Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 61400000);
        set("attitude", "friendly");
     set("demogorgon",1);
        set("rank_info/respect", "�Ϻ�");
        set("inquiry", ([
                "������" : "������ȥ�����ˣ�������λ�͹�·�Ͽ�ҪС�ġ�\n",
                "�����" : (: ask_me :),
                "��̫��" : "��С����û��Ϣ�ˣ��ߣ���֪�������š�\n",
                "����ʥ" : "�����˼Һþ�û��������Ⱦ��ˣ����������˼ҳ�������Ⱦơ������˼�����һ�����컨�����ܼ�ʮλ���ָ��֡�\n",
                  "����" : "���ô�������������������Ҳ���ں�!\n",
        ]));
        set("vendor_goods", ({
                "clone/food/jitui",
                "clone/food/jiudai",
                "clone/food/baozi",
                "/clone/cloth/caoxie",
        }));
           set_skill("force", 850);
           set_skill("dodge", 850);
           set_skill("parry", 750);
           set_skill("yan-shuangfei",700);
           set_skill("ding-unarmed",700);
           set_skill("unarmed", 750);
    
           map_skill("dodge", "yan-shuangfei");
           map_skill("unarmed", "ding-unarmed");
           map_skill("parry","ding-unarmed");
           setup();
          carry_object("/clone/cloth/cloth")->wear();
}
string ask_me()
{
        object me; 
        me = this_player();
        me->add_temp("hezuodao_ask",1);
        message("vision", HIY "�Ϻδ��һ�����������˼ҵĴ���Ҳ�����ܽе��𣿡�\n"
        NOR, environment(), this_object() );

        if (me->query_temp("hezuodao_ask") > 2){
             kill_ob(this_player());
             this_player()->kill(this_object());
         me->delete_temp("hezuodao_ask");
            return ("������Ϲ�ͷ����ƴ�ˣ�\n");
        }else
            return ("����˵һ����ɱ���㣡\n");
}        
void init()
{       
    object ob,me; 
    mapping myfam; 
    ob = this_player();
    me = this_object();
    ::init();
    if( !me->query("waiting_target") && ob->query_temp("fee_paid") ) 
        ob->delete_temp("fee_paid");
    if (me->query("startroom")!=base_name(environment()))
            return;
                
    if( interactive(ob) && !is_fighting() ) {
                if ( (myfam = ob->query("family")) 
                && myfam["family_name"] == "ؤ��" 
            && ob->query_skill("begging",1) > 60 ){
                        remove_call_out("saying");
                        call_out("saying", 0, ob);
                }else { 
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
        }
        add_action("do_name","ɱ");
        add_action("do_buy", "buy");
        add_action("do_list", "list");
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "�Ϻ�Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȼ��Ѿƣ�ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "�Ϻ��ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
        }
}
void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;
        say("\n�Ϻδ��һ���������Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��\n\n");
        remove_call_out("kicking");
        call_out("kicking", 1, ob);
        
}
void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;
        ob->move("/d/gaochang/room63");
        message("vision","ֻ����ƹ����һ����" +  ob->query("name") +
                "���˴�С����һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}


    
int do_name(string target)
{
    object me, dest, *all,ob;
 
    me = this_object();
    all = livings();
    if(me->query("waiting_target"))
        return notify_fail(me->name()+"�ٺ�һЦ����������æ���ģ�������������ɣ�\n");
    
    if( !this_player()->query_temp("fee_paid") ) 
        return notify_fail(me->name()+"�����е���ɱ����������ѽ��\n");
   if (base_name(environment())!=query("startroom")){
        return notify_fail(me->name()+"������������˵����������������˵��̫�׵��ɣ�\n");
     }
    if( !target || target==" ") 
        return notify_fail(me->name()+"��ݺݵ�˵������������Ǽһ�����֣��ҿ�û�����������ģ�\n");
    foreach (dest in livings()) 
    {
        if( target == dest->name(1) || dest->id(target) )
                break;
    }
    
    if( !dest || !environment(dest))
        return notify_fail(me->name()+"һ����Ц�������ڲ�����Ϸ�У����������ɡ�\n");
        
        if(!(target == dest->name(1) || dest->id(target)) )
        return notify_fail(me->name()+"һ����Ц�������ڲ�����Ϸ�У����������ɡ�\n");
    if (dest->is_ghost())
        return notify_fail(me->name()+"�ܲ����ˣ����Ѿ��Ǹ������ˣ��㻹�����Ҹ�ʲô��\n");
    if( this_player()->query("age")<18 )
        return notify_fail(me->name()+"�ñ��ĵ�Ŀ�⿴���㣺С��Ҳɱ����...... \n"); 
    this_player()->delete_temp("fee_paid");
    me->set("waiting_target", dest);
    me->set_temp("apply/attack",  50);
    me->set_temp("apply/defense", 50);
    me->set_temp("apply/damage",  20);
    me->delete("chat_chance");
    me->delete("chat_msg");
    if (dest==me){
             tell_object(this_player(),"�������Ҳ�İɣ�\n");
                 me->kill(this_player());
         me->set("waiting_target", this_player());
         call_out("do_chase", 1, me);
                 return 1;
        }        
    if (dest==this_player()){
             tell_object(this_player(),"��Ȼ������ˣ���ү������һ�̣�\n");
                 me->kill(this_player());
                 this_player()->kill(me);
         me->set("waiting_target", this_player());
         call_out("do_chase", 1, me);
                 return 1;
        }        
   if (userp(dest) && random(100)>35) { me->delete("waiting_target"); return notify_fail(me->name()+"�Źֵ�Ц��Ц��ҡ��ҡͷ��\n"); }
    message("vision",
        HIY+me->name()+"�ٺٺٵظ�Ц�˼�����˵����ɱ"+dest->short(1)+"?������������������!\n"+NOR,
        environment(), me );
    me->set("pursuer", 1);
        ob=this_player();
    if ((ob->query_temp("pker_starttime")+900*ob->query_temp("pker_time")) <ob->query("mud_age")){
                ob->set_temp("pker_starttime",ob->query("mud_age"));
                ob->delete_temp("pker_time");
        }
    ob->add_temp("pker_time",1);

    set_name("����¥", ({ "wuzhong lou", "lou", }) );
   set("long","������¥�����������㼸���������κε�ϲŭ���֡�\n");
        delete("inquiry");
   command("go west");
    CHANNEL_D->do_channel(me,"sys",sprintf("%s��Ӷ"+me->name()+"ɱ%s",this_player()->query("name"),dest->query("name")));
    call_out("do_chase", 1, me);
    
    return 1;
}
int accept_object(object who, object ob)
{
        object me=this_object();
        if (ob->query("money_id") && ob->value() >= 10000000
        && !this_object()->query("waiting_target")) 
    {
       if( this_player()->query("age")<16 ) 
      {
        tell_object(who, me->name()+"����������С���ӵ������Ҳ�������ؼ��������ɡ�\n");
        return 1;
      }
        tell_object(who, me->name()+"�����������ã�ˬ��˵�ɣ���Ҫ�Ұ���ɱ˭��\n");
        tell_object(who, "����룺ɱ Ŀ��\n");
        who->set_temp("fee_paid",1);
        return 1;
    }
    else if (ob->query("money_id") && ob->value() < 10000000) 
    {
        tell_object(who, me->name()+"�ٺ�һЦ��˵�������������Ǯ�� �����ҿ�û�����㰡��\n");
        return 1;
    }
    return 0;
}
int do_chase(object me)
{
    
    object dest;
    dest = me->query("waiting_target");
    
    if( !objectp(dest) || !environment(dest) )  
    {
        call_out("waiting", 0, me);
        return 1;
    }
    
    if ( !environment(dest)->query("fight_room") || !environment(dest)->query("freeze") )
    {
        message("vision",me->name()+"���˳�ȥ��\n" NOR, environment(me));
        me->move(environment(dest));
        message_vision("$N���˹�����\n" NOR, me);
        me->set_leader(dest);
        command("look " + dest->query("id"));
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
    if( objectp(dest) && present(dest, environment(me)))
    {
        message_vision(HIR "$N�������ԣ�ͻȻ��$n���𹥻���\n" NOR, me, dest);
        me->set_leader(dest);
        me->kill_ob(dest);
        dest->kill_ob(me);
    }
    else
        call_out("waiting", 1, me);     
    
    return 1;
}

void killed_enemy(object obj)
{
        object me=this_object();
    if (obj!=me->query("waiting_target"))
       call_out("do_chase",1,me);
        else
        call_out("do_back", 1, me);
}


int waiting(object me)
{
    object dest;
    dest = me->query("waiting_target");
    
    if ( objectp(dest) )
    {
        if (dest->is_ghost())
        {
            call_out("do_back", 1, me);
            return 1;
        }else if (me->is_fighting() && present(dest, environment(me)))
        {
            return 1;
        }else if (living(me) && !environment(dest)->query("no_fight"))
        {
            call_out("do_chase", 0, me);
            return 1;
        }
    }else return do_back(me);
    
    remove_call_out("waiting");
    call_out("waiting", 60, me);
    return 1;
}

int do_back(object me)
{
    me->move("/d/kunlun/sbxd");
    me->delete("waiting_target");
        set_name("�Ϻ�", ({ "lao he", "he", "xiao er", "waiter" }) );
        set("long", "�Ϻ���Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
    message("vision", me->name(1)+"���˽��������������ϵĳ������ѽ��ϵ�Ѫ��Ĩ�øɾ���\n"
        "������һЦ˵��������ү���ӣ�����ɵøɾ����䣬����������ʲ���»��������ҡ�\n", 
        environment(), me );
    me->set_leader(0);
    me->set("inquiry", ([
                "������" : "������ȥ�����ˣ�������λ�͹�·�Ͽ�ҪС�ġ�\n",
                "�����" : (: ask_me :),
                "��̫��" : "��С����û��Ϣ�ˣ��ߣ���֪�������š�\n",
                "����ʥ" : "�����˼Һþ�û��������Ⱦ��ˣ����������˼ҳ�������Ⱦơ�
�����˼�����һ�����컨�����ܼ�ʮλ���ָ��֡�\n",
                  "����" : "���ô�������������������Ҳ���ں�!\n",
        ]));

    return 1;
}


int return_home(object home)
{
    object me=this_object();
     if( !me->query("waiting_target") )
     return ::return_home(home);
   return 1;
}

