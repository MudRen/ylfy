// modified by wind
//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "武侯祠");
        set("long", @LONG

          丞相祠堂何处寻？锦官城外柏森森。
          映阶碧草自春色，隔叶黄鹏空好音。
          三顾频烦天下计，两朝开济老臣心。
          出师未捷身先死，长使英雄泪满襟?
   这里就是被川人敬仰的武侯祠.这里安葬着三国时代的
一代贤臣诸葛亮,常有成都本地人和游客前来参拜。四周参
天大树环绕着巨大陵墓,大树上不时传来几声画眉鸟清脆的
叫声。你来念着“出师未捷身先死”,心中不由得一阵黯然。
西面有座陵墓。
LONG
        );

        
        set("valid_startroom", 1);
             set("exits", ([
                "west" : __DIR__"lingmu",
                "east" : __DIR__"beijie1",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}

 
