// ĵ�������.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

// amount: ��λ��gold
int can_afford(object me,int amount)
{
        int total;
        object thgold,thcash,gold;
        thgold = present("thousand-gold_money",me);
        thcash = present("thousand-cash_money",me);
        gold = present("gold_money",me);
        total = 0;
        if( thgold ) total += thgold->query_amount()*1000;
        if( thcash ) total += thcash->query_amount()*10;
        
        if( gold ) total += gold->query_amount();
        if( total < amount ) return 0;
        return 1;
}
// amount: ��λ��gold
int pay_money(object me,int amount)
{
        int total;
        object thgold,thcash,gold;

        thgold = present("thousand-gold_money",me);
        thcash = present("thousand-cash_money",me);
        gold = present("gold_money",me);
        total = 0;
        if( thgold ) {
            total += thgold->query_amount()*1000;
            destruct(thgold);
        }
        if( thcash ) {
            total += thcash->query_amount()*10;
            destruct(thcash);
        }
        if( gold ) {
            total += gold->query_amount();
            destruct(gold);
        }
        if( total < amount ) return 0;
                total-=amount;
        if( total > 1000 ) {
            thgold=new(THGOLD_OB);
            if (!thgold->move(me)) thgold->move(environment(me));
                thgold->set_amount(total/1000);
                total %= 1000;
        }
        if( total > 10 ) {
        thcash=new(THCASH_OB);
        if (!thcash->move(me)) thcash->move(environment(me));
        thcash->set_amount(total/10);
            total %= 10;
        }
    if( total > 0 ){
        gold=new(GOLD_OB);
        if (!gold->move(me)) gold->move(environment(me));
        gold->set_amount(total);
    }
}

varargs protected void
create_food(string nmstr, string* idlist, string longstr)
{
        object obj;

        obj = new(__DIR__"obj/food");
        obj->set_name(nmstr, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", GRN+"һ����������, �������"+nmstr+"��\n"+NOR);
        obj->move(this_object());
}

varargs protected void
create_water(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;

        obj = new(__DIR__"obj/water");
        obj->set_name(cup, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", YEL+"һ���ɿڵ�" + nmstr + "��\n" + NOR);
        obj->set("liquid/name", nmstr);
        obj->move(this_object());
}

varargs protected void
create_wine(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;

        obj = new(__DIR__"obj/wine");
        obj->set_name(cup, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", RED+"һ��������" + nmstr + "��\n" + NOR);
        obj->set("liquid/name", nmstr);
        obj->move(this_object());
}

void create()
{
        set("short", HIR"ĵ������"NOR);
        set("long", @LONG
�����ƹ�һ����������磬ӭ��ǽ�Ϲ���һ����ĵ�����ޡ�ͼ��ĵ����
�й����������Ը������ơ�ͼ�����: �ľ����˳ʶ��㣬��԰��ɫ��Ⱥ����
��������һ��ĵ�����⾫�����ڳ����ݻ���������һ�ŵ��ľ����Ƕ��
��Բ��������ʮ���������������ֺ�ľ�Σ��������磬�������ԡ�
    �����������¥��õ����������ƽ����һ�ݲ˵�(menu)��
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"zxlpath",
        ]));
        set("no_sleep_room",1);
        set("item_desc", ([
                "menu": @TEXT
�а��ʽ��ϯ, ��ӭ�ݹˣ�

        order marry:    ���Ŷ�����        (1�����ƽ�)

        order end:      ��  ��

TEXT
        ]) );
//        create_door("out", "��ľ�λ���", "enter", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
        set("no_user", 1);
}

void init()
{
        object me;

        add_action("do_order", "order");
        add_action("do_broadcast", "broadcast");
        if (query("order_owner")) {
                me = this_player();
                me->set("food", me->query("food") / 8);
                me->set("water", me->query("water") / 8);
        }
        add_action("do_get", "get");
}
int do_get(string arg)
{
	if (!arg)	return 0;
	if (arg=="all" && query("order_owner")){
		write("�������޷��·�����ô���θ�ڣ�\n");
		return 1;
	}
	return 0;
}

int do_broadcast(string arg)
{
        string type;
        string mesg;
        object me;

        me = this_player();
        if (query("order_owner") != me->query("id"))
                return 0;
        type = query("order_type");
        if (type == "marry") {
                mesg = me->name() + "����������¥ĵ�������к��Ŷ��������  !!!\n";
        } else if (type == "birthday") {
                mesg = me->name() + "����������¥ĵ������������������  !!!\n";
        } else if (type == "player") {
                mesg = me->name() + "����������¥ĵ���������·Ӣ�ۺ���  !!!\n";
       }
        message("chat", BOLD+"��ͨ�桿"+mesg+NOR, users() );
        return 1;
}

int do_order(string arg)
{
        object me, env;
        object* oblist;
        string mesg;
        int idx;

        me = this_player();
        env = this_object();
        mesg = query("order_owner");
        if (mesg && (arg == "end") && (mesg == me->query("id"))) {
                mesg = "ĵ��������������  !!!\n";
                message("chat", BOLD+"��ͨ�桿"+mesg+NOR, users() );
                delete("order_owner");
                delete("order_type");
                oblist = all_inventory(env);
                for(idx=0; idx<sizeof(oblist); idx++) {
                        if (!objectp(oblist[idx]))
                                continue;
                        if (userp(oblist[idx]))
                                continue;
                        destruct(oblist[idx]);
                }
                return 1;
        }
        if (mesg)
                return notify_fail("�����Ѿ����˰�����.\n");
         notify_fail("��û���㹻��Ǯ����Ǯ����.\n");
        if (arg == "marry") {
                mesg = me->name() + "����������¥ĵ�������к��Ŷ��������  !!!\n";
                if (can_afford(me,10000) == 0)
                        return 0;
                pay_money(me,10000);
                create_water(HIG"������"NOR, ({ "tea" }), MAG"��ɰ����"NOR );
                create_water(RED"�ն���"NOR, ({ "tea" }), WHT"ˮ��յ"NOR );
                create_wine(WHT"�׾�"NOR, ({ "wine" }), HIW"�´ɱ�"NOR );
                create_wine(GRN"��Ҷ��"NOR, ({ "wine" }), GRN"��䱭"NOR );
                create_wine(YEL"���˻ƾ�"NOR, ({ "wine" }), HIY"������"NOR );
                create_wine(HIR"Ů����"NOR, ({ "wine" }), MAG"��̴��"NOR );
                create_wine(WHT"ę́��"NOR, ({ "wine" }), YEL"�̽�"NOR );
                create_wine(RED"�𻨾�"NOR, ({ "wine" }), WHT"������"NOR );
                create_food(YEL"���ֻ���"NOR,({"peanut"}) );
                create_food(HIR"�������"NOR,({"jujube"}) );
                create_food(RED"ϲ��"NOR,({"sugar"}) );
                create_food(HIW"���͹���"NOR,({"melon seeds","seeds"}) );
                create_food(HIG"���ݴ���"NOR, ({ "spring roll","roll" }) );
                create_food(HIC"��Ƭ����"NOR, ({"fish"}) );
                create_food(HIW"������˺��"NOR, ({"chicken"}) );
                create_food(HIR"��������"NOR, ({"fish"}) );
                create_food(HIY"����ˮ��"NOR, ({ "dumpling" }) );
                create_food(RED"�������"NOR, ({ "chafing dish","dish" }) );
                create_food(HIR"�ͼ��з"NOR, ({ "crab" }) );
                create_food(HIY"������"NOR, ({ "meat" }) );
                create_food(YEL"�ҳ�����"NOR, ({ "bean curd" }) );
                create_water(GRN"�����"NOR, ({ "tea" }), MAG"��ɰ����"NOR );
                create_water(HIG"��ɽ����"NOR, ({ "tea" }), RED"����յ"NOR );
                create_water(HIW"����"NOR, ({ "milk" }), WHT"������"NOR );
                create_wine(RED"���껨��"NOR, ({ "wine" }), HIW"�δɱ�"NOR  );
                create_wine(WHT"����Һ"NOR, ({ "wine" }), WHT"������"NOR );
                create_wine(WHT"�׾�"NOR, ({ "wine" }), HIW"�´ɱ�"NOR );
                create_wine(HIR"�ſ���"NOR, ({ "wine" }), HIG"��ͭ��"NOR  );
                create_wine(HIW"͸ƿ��"NOR, ({ "wine" }), WHT"������"NOR  );
                create_food(HIY"���ݰǼ�"NOR, ({ "chicken" }) );
                create_food(HIG"���ݴ���"NOR, ({ "spring roll","roll" }) );
                create_food(YEL"��ଷ�"NOR, ({"rice"}) );
                create_food(RED"�����Ƭ"NOR, ({"fish meat","meat"}) );
                create_food(RED"���⴮"NOR, ({ "mutton" }) );
                create_food(HIR"������"NOR, ({ "chafing dish","dish" }) );
                create_food(HIY"������Ѽ"NOR, ({ "duck" }) );
                create_food(HIW"��ϲ����"NOR, ({ "bean curd" }) );
                create_food(YEL"�л���"NOR, ({ "chicken" }) );
                create_food(HIW"��ϲ����"NOR, ({ "bean curd" }) );
                create_food(HIG"���ݴ���"NOR, ({ "spring","roll" }) );
                create_food(HIC"��Ƭ����"NOR, ({"fish"}) );
                create_food(RED"���⴮"NOR, ({ "mutton" }) );
                create_food(HIY"��֦����"NOR, ({"rice"}) );
                create_food(HIR"������˿"NOR, ({"fish meat","meat"}) );
                create_food(HIY"���ݰǼ�"NOR, ({ "chicken" }) );
                create_food(RED"�������"NOR, ({ "chrafing dish","dish" }) );
                create_food(HIY"������Ѽ"NOR, ({ "duck" }) );
                create_food(HIW"��ն��"NOR, ({ "chicken" }) );
                create_food(YEL"������"NOR, ({ "meat" }) );
                create_food(HIR"������"NOR, ({ "chafing dish","dish" }) );
                create_food(HIR"���Ŷ���"NOR, ({ "bean curd" }) );
                create_food(RED"�����Ƭ"NOR, ({"fish meat","meat"}) );
                create_food(YEL"��ଷ�"NOR, ({"rice"}) );
                create_food(HIW"������˺��"NOR, ({"chicken"}) );
                create_food(HIR"��������"NOR, ({"fish"}) );
                create_food(HIY"����ˮ��"NOR, ({ "dumpling" }) );
                create_water(HIW"����"NOR, ({ "milk" }), CYN"�໨��"NOR );
                create_water(GRN"�����"NOR, ({ "tea" }), MAG"��ɰ����"NOR );
                create_water(GRN"���ݴ�"NOR, ({ "tea" }), MAG"��ɰյ"NOR );
                create_water(HIG"��ɽ����"NOR, ({ "tea" }), RED"����յ"NOR );
                create_water(HIR"��ë��"NOR, ({ "tea" }), CYN"����յ"NOR );
                create_wine(HIW"�ھ�"NOR, ({ "wine" }), WHT"��֬����"NOR );
                create_wine(WHT"����׾�"NOR, ({ "wine" }), YEL"Ϭ�Ǳ�"NOR );
                create_wine(RED"���Ѿ�"NOR, ({ "wine" }), HIW"ҹ�Ɑ"NOR );
                create_wine(WHT"������"NOR, ({ "wine" }), CYN"��ͭ��"NOR );
                create_wine(HIG"�ٲݾ�"NOR, ({ "wine" }), RED"���ٱ�"NOR );
                create_wine(HIR"״Ԫ��"NOR, ({ "wine" }), WHT"�Ŵɱ�"NOR );
                create_wine(GRN"�滨��"NOR, ({ "wine" }), HIG"��䱭"NOR );
                create_wine(HIW"��¶��"NOR, ({ "wine" }), WHT"������"NOR );
        }
         else {
                return notify_fail("��Ҫ��ʲô��ϯ?\n");
        }
        message("chat", BOLD+"��ͨ�桿"+mesg+NOR, users() );
        set("order_owner", me->query("id"));
        set("order_type", arg);
        return 1;
}
int valid_leave(object me, string dir)
{
        if (me->query("id") != query("order_owner"))
                return 1;
        return notify_fail(RED + "���� order end ������������뿪��\n" + NOR);
}


