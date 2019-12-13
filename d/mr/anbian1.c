#include <room.h>
#include <ansi.h>
inherit ROOM;
mapping *paizi=({
    ([  "name":"����С��",
        "id":"xiaozhu",
        "file":__DIR__"zhou6",                    
        "value":500
     ]),
    ([  "name":"������",
        "id":"yanziwu",
        "file":__DIR__"zhou",
"value":500
    ]),               
});
string look_paizi();
int do_go(string);
void create()
{
         set("short","����");
         set("long", @LONG
������٢��ɽׯ��һ��С��ͷ���������ϴ����Ե���Ľ�����ҵ���أ�
�����е�Ӣ�ۺ����Ƕ�ʮ����Ľ�������µ������룬��Ϊ���������˲�
֪���˲����ġ��Ա�֮������ʩ�����ķ�Դ�أ���Ľ������һ������
ס�����������һλ�ϴ���ר������ȥ�������������ʿ����һ��
���߹��������ҵ���������Ц����æӭ��ǰȥ���ڰ�����һ������(paizi)��
LONG
   );
         set("outdoors","mr");
         set("exits",([
             "north" : __DIR__"xiaojing1-0",
]));
         set("item_desc",([
             "paizi" : (: look_paizi :)     
]));
}
void init()
{
    add_action("do_go", "qu");
}

string look_paizi()
{
    string str="";
    int i=sizeof(paizi);

//      if (ob->query("family/family_name") != "����Ľ��") i--;

    while (i--) {
        str += paizi[i]["name"];
        str += "(" + paizi[i]["id"] + ") ";
        str += MONEY_D->price_str(paizi[i]["value"]) + "\n";
    }

    return str;
}

void do_move(object ob, int i)
{
//   message_vision(YEL"\n$N��Ǯ�������ң�������$N����һ��С�ۡ�\n\n"NOR,ob);
        ob->move(paizi[i]["file"]);
}

int do_go(string arg)
{
    object ob=this_player();
    int i=sizeof(paizi);

    if (!arg) return notify_fail("��Ҫȥ���\n");
    if (ob->is_busy() || ob->is_fighting())
        return notify_fail("����æ���أ�\n");

    //  if (ob->query("family/family_name") != "����Ľ��") i--;
    
    while(i--) {
      if (arg == paizi[i]["id"]) 
          {
            if(ob->query("family/family_name") != "����Ľ��")
            {
              switch (MONEY_D->player_pay(ob, paizi[i]["value"]))
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
