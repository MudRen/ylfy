// salt seller
#include <dbase.h>
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
void create()
{
    set_name("����", ({"salt seller","seller"}));
    set("long",
    "����һ����ĸߴ�Ľ����ˣ����۴�׳��������Բ��\n"
    );
    set("gender", "����");
set("no_get", 1);	
    set("attitude", "friend");
    set("class", "swordman");
    set("age", 20+random(30));
    set("str", 25+random(10));
    set("dex", 25+random(10));
    set("int", 25+random(10));
    set("con", 25+random(10));
    set("qi", 1500);
    set("max_qi", 1500);
     set("jing", 10000);
    set("max_jing", 1000);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiaji", 50+random(100));
    set("combat_exp", 10000+random(100000));
    set_skill("force", 20+random(80));
    set_skill("dodge", 20+random(60));
    set_skill("unarmed", 20+random(150));
    set_skill("parry", 20+random(80));
    
    setup();
    carry_object("/clone/cloth/blk_cloth")->wear();
    
}
void init()
{
    ::init();
    remove_call_out("greeting");
    call_out("greeting", 1, this_player());
    add_action("do_buy", "buy");
}
void greeting(object ob)
{
    object me;
    me = this_object();
        if( !ob || environment(ob) != environment() ) return;
    if (interactive(ob))
            command("whisper "+ob->query("id")+" ��λ"+RANK_D->query_respect(ob)+"Ҫ����(salt)ô�������һ������������Ү��");
}
int pay_player(object who, int amount)
{
    object ob;
    int total;
    if( amount < 1 ) amount = 1;
        if( amount/10000 ) {
        if (!ob=present("gold_money", who)){
                    ob = new(GOLD_OB);
            if (!ob->move(who)) ob->move(environment(who));
        }else total=ob->query_amount();
                ob->set_amount(amount/10000+total);
                amount %= 10000;
    }
    if( amount/100 ) {
        if (!ob=present("silver_money", who)){
                    ob = new(SILVER_OB);
            if (!ob->move(who)) ob->move(environment(who));
        }else total=ob->query_amount();
                ob->set_amount(amount/100+total);
        amount %= 100;
    }
    if( amount ) {
        if (!ob=present("coin_money", who)){
            ob = new(COIN_OB);
            if (!ob->move(who)) ob->move(environment(who));
        }else total=ob->query_amount();
                ob->set_amount(amount+total);
    }
    return 1;
}
int do_buy(string arg)
{
    string items,targ;
    object *env,me,ob,obj,room;
    int i,amount=1;
    ob=this_player();
    me=this_object();
    if (! room=find_object(me->query("startroom")))
        room=load_object(me->query("startroom"));
    if (room!=environment()){
        command("say ����û�������һ�ȥ��˵�ɣ�");
        return 1;
    }
    env=all_inventory(room);
    for (i=0;i<sizeof(env);i++){
        if (env[i]==me || env[i]==ob)   continue;
        if (env[i]->is_character() && !env[i]->is_corpse() ){
            command("whisper "+ob->query("id")+" �����Ŀ�ڶ࣬��λ"+RANK_D->query_respect(ob)+"���������ɣ�");
            command("say �߿����߿���˭˵��������ʲô�����ģ�"+RANK_D->query_self_rude(me)+"���������⹴����");
            return 1;
        }
    }
    targ="";
    if ( !arg )
        return notify_fail("��Ҫ��ʲô������\n");
    if(sscanf(arg, "%d %s from %s",amount,items, targ)!=3 )
        if(sscanf(arg, "%s from %s", items, targ)!=2 )
            if( sscanf(arg, "%d %s",amount,items)!=2 )
                items=arg;
    if(targ!="")
        if (!me->id(targ))
            return notify_fail("��Ҫ��˭������\n");
    if (items == "")
        return notify_fail(items+"������ʲô�� \n");
    if ( items!="salt")
        return notify_fail(items+"������ʲô�� \n");
    if(amount<1) return notify_fail("���ٵ���һ��ɣ�\n");
//   if(time()-(int)ob->query_temp("salt_got")<=20) return notify_fail("�ղŲ�����������ô���Ȼ�������!\n");
    if(amount>1000) return notify_fail("����û��ô���ֻ���\n");
    if( ob->can_afford(100*amount) ) {
        if (!obj=present("illicit salt",ob)){
            obj=new("/clone/misc/salt");
            if (!obj->move(ob)) obj->move(environment(ob));
            obj->set_amount(amount);
        }else
            obj->add_amount(amount);
        ob->pay_money(100*amount);
        ob->set_temp("salt_got",time());
        message_vision("$N��$n����" +CHINESE_D->chinese_number(amount)+"���Ρ�\n",ob, me );
        return 1;
    } else
        return notify_fail("���Ǯ������\n");
}

void fight_ob(object ob)	
{
::fight_ob(ob);	
message_vision("$N����̾�˿����������������Ǻα���.....��˵����$nͷ��һ�á�\n",this_object(), ob);	
ob->unconcious();	
}
