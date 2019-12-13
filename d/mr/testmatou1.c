inherit ROOM;
#include <ansi.h>  
mapping *sign=({
([ "name":"����С��",
        "id":"mr",
        "file":__DIR__"duchuan",
"value":500
]),
([
"name":"������",
"id":"yanziwu",
"file" :__DIR__"zhou",
"value":1000
]),
});
string look_sign();
int do_go(string);
    void create()
    {
        set("short", "��ͷ");
set("long",@LONG
������Ľ�ݼҵļ��ͺ�Ѿ�߳���̫����ˮ����ͷ��ֻ����������������
һ�����糾���ͣ���ͷ�ߵ��ϴ���������߹���������Ц�Ǻǵ�ӭ����
ȥ���۸��(sign)��
LONG 
);
set("outdoors","mr");
set("exits",([
"north" : __DIR__"shiqiao",
]));
set("item_desc", ([
        "sign" : (: look_sign :)
    ]));
set("objects",([
//"/u/beyond/chuanfu"  : 1,
]));
    set("outdoor", "abc");

    setup();
}

void init()
{
    add_action("do_go", "qu");
}

string look_sign()
{
        object ob = this_player();
    string str="�����˴�����Ϊ������������������\n";
    int i=sizeof(sign);

        if (ob->query("family/family_name") != "����Ľ��") i--;

    while (i--) {
        str += sign[i]["name"];
        str += "(" + sign[i]["id"] + ") ";
        str += MONEY_D->price_str(sign[i]["value"]) + "\n";
    }

    return str;
}

void do_move(object ob, int i)
{
        ob->move(sign[i]["file"]);
}

int do_go(string arg)
{
    object ob=this_player();
    int i=sizeof(sign);

    if (!arg) return 0;
    if (ob->is_busy() || ob->is_fighting())
        return notify_fail("����æ���أ�\n");
        if (ob->query("family/family_name") != "����Ľ��") i--;
    while(i--) {
        if (arg == sign[i]["id"]) {
          if(ob->query("family/family_name") != "����Ľ��")
            {
              switch (MONEY_D->player_pay(ob, sign[i]["value"])) 
                {
                case 0:
                  return notify_fail("��⵰��һ�ߴ���ȥ��\n");
                case 2:
                  return notify_fail("����Ǯ��\n");
                }
              message_vision("$N�ڿڴ��﷭����ȥ���Ҵ�Ǯ��\n", ob);
              ob->start_busy(3);
              message_vision(YEL"\n$N��Ǯ�������ң�������$N����һ��С�ۡ�\n\n"NOR,ob);
            }
          else
            {
              message_vision(YEL"\n���Ҷ�$N˵����ԭ����Ľ�ݼҵ��ˣ������ϴ���\n"NOR,ob);
              message_vision(YEL"$N������С����\n"NOR,ob);
            }
            call_out("do_move", 3, ob, i);
            return 1;
        }
    }
    return notify_fail("��Ҫȥ���\n");
}
