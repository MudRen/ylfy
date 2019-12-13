#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ϲ÷�", ({ "waiter" }) );
        set("gender", "����" );
        set("age", 60);
        set("long",
                "��λ�ϲ÷���Ц�����æ��������ʱ�Ĳ�һ���Լ����ϻ��ۡ�\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 30);
        set("shen_type", 0);
        set("max_neli",5000);
        set("jiali",50);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("jiuyin-baiguzhao",200);
        set_skill("force",150);
        set_skill("sword",150);
        set_skill("bibo-shengong",100);
        set_skill("luoying-shenjian",100);
        set_skill("parry",90);
        set_skill("anying-fuxiang",100);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage",50);
        set("combat_exp", 800000);
    
        map_skill("force","bibo-shengong");
        map_skill("parry","luoying-shenjian");
        map_skill("sword","luoying-shenjian");
        map_skill("unarmed","jiuyin-baiguzhao");
        map_skill("dodge","anying-fuxiang");
    
        set("attitude", "peaceful");
        
        set("inquiry", ([
        "�����·�"  : "�����·����Ǽ�ʮ�ּ����£�Ҫ�����˵ľ�����������������ֻҪ��Ǯ...\n",
        "cloth": "�����·����Ǽ�ʮ�ּ����£�Ҫ�����˵ľ�����������������ֻҪ��Ǯ...\n",
       ]) );
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_answer","answer");
        add_action("do_ding","ding");
}
void complete(object me)
{
    object ob;
    string w_name,armor;
    
    if( !me || environment(me) != environment() ) return;
    if ((int)me->query("make_wear/time") < time() ){
        w_name=me->query("make_wear/name");
        switch (me->query("make_wear/armor")){
           case "wrists": armor=__DIR__"obj/m_wear/m_wrists";    break;
           case "scarf": armor=__DIR__"obj/m_wear/m_scarf";    break;
           case "finger": armor=__DIR__"obj/m_wear/m_finger";    break;
           case "waist": armor=__DIR__"obj/m_wear/m_waist";    break;
           case "hands": armor=__DIR__"obj/m_wear/m_hands";    break;
           case "coif": armor=__DIR__"obj/m_wear/m_coif";    break;
           case "boots": armor=__DIR__"obj/m_wear/m_boots";    break;
           case "cloth": armor=__DIR__"obj/m_wear/m_cloth";    break;
           default: me->delete("make_wear");   return;
        }
        write("�ϲ÷�����㣺�Ѿ������ˣ��͹����Ŀ��\n");
        ob=new(armor);
        ob->set("name",w_name);
        ob->move(me);
        me->delete("make_wear");
        message_vision("$N�ݸ�$nһ"+ob->query("unit")+w_name+"��\n",this_object(),me);
    }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "�ϲ÷�Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����������·��ɡ�\n");
                        break;
                case 1:
                        say( "�ϲ÷��ü����˵������λ" + RANK_D->query_respect(ob)
                                + "���������ְ�����ﲻ���㡣\n");
                        break;
        }
        call_out("complete",1,ob);
}

void dest(object ob)
{
    if (ob)     destruct(ob);
}
int accept_object(object who, object ob)
{   
    if (who->query("make_wear")){
        command("say ���ϴζ�����"+who->query("make_wear/name")+"��δ����أ����´������ɡ�\n");
        return 0;
    }
    if (ob->query("money_id") && ob->value() >= 10000 ){
        call_out("dest",1,ob);
        who->set_temp("get_wear",1);
        message("vision","�ϲ÷���æһ������\n",who);
        command("say ��������Զ������·��Σ�\n"+
          "     ����(waist)\n"+
          "     ����(wrists)\n"+
          "     ָ��(finger)\n"+
          "     ����(hands)\n"+
          "     Χ��(scarf)\n"+
          "     ͷ��(coif)\n"+
          "     ѥ��(boots)\n"+
          "     �·�(cloth)\n");       
        command("say ��λ"+RANK_D->query_respect(who)+"Ҫ����ʲô���Σ������˸�����(answer)��\n");
        return 1;
    }
    command("say ������������Ҫһ���ƽ�");
    return 0;
}

int do_answer(string arg)
{
    object me,ob;
    string str;
    
    me = this_player();
    if (me->query("make_wear"))        return 0;
    if(!(me->query_temp("get_wear") ) ){
        write("����ȸ�Ǯѽ��\n");
        return 1;
    }
    
    if(!arg){
       write("��Ҫ��ʲô���Σ�\n");
       return 1;
    }
    message("vision",me->name()+"���ϲ÷�����˵�˼��䡣\n",environment(me), ({me}) );

    switch (arg) {
      case "waist"  :
         ob=present("my waist",me);
         str="����";
         break;
      case "wrists"   :        
         ob=present("my wrists",me);
         str="����";        
         break;
      case "finger" :   
         ob=present("my finger",me);
         str="ָ��";    
         break;
      case "hands" :
         ob=present("my hands",me);
         str="����";
         break;
      case "scarf" :
         ob=present("my scarf",me);
         str="Χ��";
         break;
      case "coif" :
         ob=present("my coif",me);
         str="ͷ��";
         break;
      case "boots" :
         ob=present("my boots",me);
         str="ѥ��";
         break;         
      case "cloth" :
         ob=present("my cloth",me);
         str="�·�";
         break;
      default :
        message_vision(HIC "$Nһ�����ɵؿ���$n��ʲô���Σ�\n" NOR,this_object(),me);
        return notify_fail("���²��ɶ�Ϸ��������!!\n");
    }
    if (ob){
        say("�ϲ÷�һ��ãȻ�����Ѿ���"+str+"�ˣ�������ʲô���ѵ���������\n");
        return 1;
    }
    command("say ����λ"+RANK_D->query_respect(me)+"��"+str+"�����ְɣ�(ding "+str+"����������(ʹ����ɫ��ο�help nick))\n");
    me->set_temp("wear",arg);
    me->delete_temp("get_wear");
    return 1;
}

int do_ding(string w_name)
{
    object me;
    string armor;

    if( !w_name )
        return notify_fail("�ϲ÷������˵����������ĵ����ƺ��ٸ����ҡ�\n");
    me = this_player();
    armor = me->query_temp("wear");
    me->delete_temp("wear");
    w_name = replace_string(w_name, "$BLK$", BLK);
    w_name = replace_string(w_name, "$RED$", RED);
    w_name = replace_string(w_name, "$GRN$", GRN);
    w_name = replace_string(w_name, "$YEL$", YEL);
    w_name = replace_string(w_name, "$BLU$", BLU);
    w_name = replace_string(w_name, "$MAG$", MAG);
    w_name = replace_string(w_name, "$CYN$", CYN);
    w_name = replace_string(w_name, "$WHT$", WHT);
    w_name = replace_string(w_name, "$HIR$", HIR);
    w_name = replace_string(w_name, "$HIG$", HIG);
    w_name = replace_string(w_name, "$HIY$", HIY);
    w_name = replace_string(w_name, "$HIB$", HIB);
    w_name = replace_string(w_name, "$HIM$", HIM);
    w_name = replace_string(w_name, "$HIC$", HIC);
    w_name = replace_string(w_name, "$HIW$", HIW);
    w_name = replace_string(w_name, "$NOR$", NOR);
    w_name += NOR;
    me->set("make_wear/name",w_name);
    me->set("make_wear/armor",armor);
    me->set("make_wear/time",time()+7200);
    command("say ��λ"+RANK_D->query_respect(me)+"����"+w_name+CYN+"����һ���º���ȡ�ա�\n");
    return 1;
}


