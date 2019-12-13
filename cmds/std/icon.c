#include <ansi.h>
#include <liebiao.h>
inherit F_CLEAN_UP;
#define MAX_ICONS 2159

int help();

int main(object me,string arg)
{
	int ico;
        string iicon="";
        string icon="";
        string iiicon="";
        iicon=(me->query("gender") == "男性" )?"50001":"50002";
        if(!me->query("icon"))
        {
            iiicon=iicon;
            icon=HIR"你的图象是系统默认的: "+HIG+iicon+NOR;
        }
        else
        {
            iiicon=me->query("icon");
            icon="你当前的图象编号为 "+HIG+iiicon+NOR;
        }
        
	if(arg)
	{
              if(sscanf(arg,"%d",ico)!=1 || ico < 1110 || ico >1246)
			return help();
		iiicon = "0" + ico;
                icon="你当前的图象编号为：0" + ico ;
		write("你的图标已经被修改为 "+HIG+iiicon+NOR+" 了！\n");
		me->set("icon",iiicon);
	}
	else help();
        
        tell_object(me,icon);
        tell_object(me,L_ICON(iiicon));
	return 1;
}

int help()
{
	write("命令格式："+HIY+"icon [图标编号]\n"+NOR+
		"    你可以用本命令查询和修改自己的头像编号。\n"+
		"    目前图标可以选择范围是"+HIR+" 50001 - 60000 "+NOR+" 。\n");
	return 1;
}


