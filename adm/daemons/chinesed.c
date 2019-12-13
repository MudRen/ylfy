// chinesed.c
// by Annihilator@ES
// modified by Xiang@XKX

#include <localtime.h>
#ifndef DATA_DIR
#define DATA_DIR 	"/data/"
#endif
#define E2C_DICTIONARY	DATA_DIR + "e2c_dict"
inherit F_SAVE;
// some constatns
nosave string *c_digit = ({ "零","十","百","千","万","亿","兆" });
nosave string *c_num = ({"零","一","二","三","四","五","六","七","八","九","十"});
nosave string *sym_tian = ({ "甲","乙","丙","丁","戊","己","庚","辛","壬","癸" });
nosave string *sym_di = ({ "子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥" });
nosave string *week = ({ "Mon","Tue","Wed","Thu","Fri","Sat","Sun" });
nosave string *c_week = ({ "星期一","星期二","星期三","星期四","星期五","星期六","星期日" });
nosave string *month = ({ "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" } );
nosave string *c_month = ({"一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月" });
nosave string *unit = ({ "万","亿","兆" });
mapping dict = ([]);
void add_translate(string key, string chn);
void remove_translate(string key);

void create()
{
	seteuid(getuid());
	restore();
}

void remove()
{
	save();
}

// 以前的有问题，重新编写了这个函数。by Wenwu
string chinese_number(mixed i)
{
        // 若输入参数为 integer (会 overflow) 
        if( intp(i) )
        {
                if (i < 0)
                        return "负" + chinese_number(-i);
                if (i < 11)
                        return c_num[i];
                if (i < 20)
                        return c_digit[1] + c_num[i - 10];
                if (i < 100)
                {
                        if (i % 10)
                                return c_num[i / 10] + c_digit[1] + c_num[i % 10];
                        else
                                return c_num[i / 10] + c_digit[1];
                }
                if (i < 1000)
                {
                        if (i % 100 == 0)
                                return c_num[i / 100] + c_digit[2];
                        else if (i % 100 < 10)
                                return c_num[i / 100] + c_digit[2] +
                                c_num[0] + chinese_number(i % 100);
                        else if (i % 100 < 10)
                                return c_num[i / 100] + c_digit[2] +
                                c_num[1] + chinese_number(i % 100);
                        else
                                return c_num[i / 100] + c_digit[2] + 
                                chinese_number(i % 100);
                }
                if (i < 10000)
                {
                        if (i % 1000 == 0)
                                return c_num[i / 1000] + c_digit[3];
                        else if (i % 1000 < 100)
                                return c_num[i / 1000] + c_digit[3] +
                                c_num[0] + chinese_number(i % 1000);
                        else 
                                return c_num[i / 1000] + c_digit[3] +
                                chinese_number(i % 1000);
                }
                if (i < 100000000)
                {
                        if (i % 10000 == 0)
                                return chinese_number(i / 10000) + c_digit[4];
                        else if (i % 10000 < 1000)
                                return chinese_number(i / 10000) + c_digit[4] +
                                c_num[0] + chinese_number(i % 10000);
                        else
                                return chinese_number(i / 10000) + c_digit[4] +
                                chinese_number(i % 10000);
                        }
                if (i < 1000000000000)
                {
                        if (i % 100000000 == 0)
                                return chinese_number(i / 100000000) + c_digit[5];
                        else if (i % 100000000 < 1000000)
                                return chinese_number(i / 100000000) + c_digit[5] +
                                c_num[0] + chinese_number(i % 100000000);
                        else 
                                return chinese_number(i / 100000000) + c_digit[5] +
                                chinese_number(i % 100000000);
                }
                if (i % 1000000000000 == 0)
                        return chinese_number(i / 1000000000000) + c_digit[6];
                else
                if (i % 1000000000000 < 100000000)
                        return chinese_number(i / 1000000000000) + c_digit[6] +
                        c_num[0] + chinese_number(i % 1000000000000);
                else
                        return chinese_number(i / 1000000000000) + c_digit[6] +
                        chinese_number(i % 1000000000000);
            }
            // 若输入参数为 string (无限位数处理)
        else if( stringp(i) && i != "")
        {
                   int j, k, *n=({}), usize = sizeof(unit);
                string *u=({""});
                string msg;
                
                if( i[0] == '-' ) return "负" + chinese_number(i[1..]);
                
                // 将数字依四位数拆解
                while( (msg = i[<(j+=4)..<(j-3)])!="" )
                {                        
                        n += ({ to_int(msg) });
                        if( j != 4 ) u += ({ unit[k++%usize] });
                }
                
                j = k = sizeof(n);
                        
                while(j--)
                        if( n[j] ) msg += (j+1<k ? (n[j+1] && n[j]>999 ? chinese_number(n[j]):"零"+chinese_number(n[j])):chinese_number(n[j])) + u[j];
                        else if( u[j] == unit[usize-1] ) msg += unit[usize-1];

                return msg;
        }
        else return "错误数值";
}

string query_save_file()
{
	return E2C_DICTIONARY;
}

string chinese(string str)
{
	if (!undefinedp(dict[str]))
		return dict[str];
	else
		return str;
}

void remove_translate(string key)
{
	map_delete(dict, key);
	save();
}

void add_translate(string key, string chn)
{
	dict[key] = chn;
	save();
}

void dump_translate()
{
	string *k, str;
	int i;
	
	str = "";
	k = keys(dict);
	for (i = 0; i < sizeof(k); i++) 
		str += sprintf("%-30s %s\n", k[i], dict[k[i]]);
	write_file("/CHINESE_DUMP", str);
}

string chinese_date(int date)
{
	mixed *local;
	if (date<0)	date=1;
	local = localtime(date);
	
	return sprintf("%s%s年%s月%s日%s时%s刻",
                sym_tian[local[LT_YEAR] % 10], sym_di[local[LT_YEAR] % 12],
                chinese_number(local[LT_MON] + 1),
                chinese_number(local[LT_MDAY] + (local[LT_HOUR] > 23 ? 1 : 0)),
                sym_di[((local[LT_HOUR] + 1) % 24) / 2],
                chinese_number((local[LT_MIN]+1) % 2 * 2 + 
                local[LT_MIN] / 30 + 1) );
 //               chinese_number((local[LT_MIN]+1)/15+1 ));
//                 local[LT_MIN] / 30 + 1) );
}

string ture_date(string arg)
{
    string week1,month1,t_year;
    int i,num,num1,num2,num3,year;
    int f_year = 0;
    int s_year = 0;
    int e_year = 0;
    int o_year = 0;
    sscanf(arg,"%s %s %d %d:%d:%d %d",week1,month1,num,num1,num2,num3,year);
   
    for(i = 0; i < sizeof(week); i++ )
     {
     if(week[i] == week1) {
     week1 = c_week[i]; break;
      }  
     }
    for(i = 0; i< sizeof(month); i++ )
    {
     if(month[i] == month1) {
     month1 = c_month[i]; break;
     }
    }
    t_year = "";
    f_year = year / 1000;
    t_year = chinese_number(f_year);
    s_year = (year - f_year * 1000) / 100; 
    t_year += chinese_number(s_year);
    e_year = (year - (f_year * 1000) - (s_year * 100)) / 10;
    t_year += chinese_number(e_year);
    o_year = year -  (f_year * 1000) - (s_year * 100) - (e_year * 10); 
    t_year += chinese_number(o_year)+"年";
    return sprintf(t_year+month1+"%s日%s点%s分%s秒"+" "+week1,chinese_number(num),chinese_number(num1),chinese_number(num2),chinese_number(num3));
} 

string chinese_period(int t)
{
        int y, n, d, h, m, s;
        string time;

        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t % 30;             t /= 30;
        n = t % 12;             t /= 12;
        y = t;

        time = "";

        if(y) time = chinese_number(y) + "年又";
        if(n) time += chinese_number(n) + "个月"        + (strlen(time)?"":"又");
        if(d) time += chinese_number(d) + "天"          + (strlen(time)?"":"又");
        if(h) time += chinese_number(h) + "小时"        + (strlen(time)?"":"又");
        if(m) time += chinese_number(m) + "分"          + (strlen(time)?"":"又");
        time += chinese_number(s) + "秒";

        return time;
}

string chinese_time(int type,string get_time)
{
        string e_time, week, month, year;
        string c_week, c_year, c_month, c_time;
        int day, hour, minute, second;
        string *month_name = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
                "Aug","Sep","Oct","Nov","Dec"});
        string *week_name = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});

        if ( stringp(get_time) )
                e_time = get_time;
        else e_time = ctime(time());

        // e_time must is ctime(time string) like "Sun May  3 00:52:12 1998"
        sscanf(e_time,"%s %s %d %d:%d:%d %s", week, month, day, hour, minute, second, year);

        c_week  = chinese_number(member_array(week, week_name) + 1);
        c_month = chinese_number(member_array(month, month_name) + 1);

        c_year  = sprintf("%s%s%s%s",
                         chinese_number(year[0]-48),
                         chinese_number(year[1]-48),
                         chinese_number(year[2]-48),
                         chinese_number(year[3]-48));

        c_year = c_year + "年";
        c_month  = c_month + "月";
        c_week = " 星期"+c_week;

        c_time = chinese_number(day) + "日";
        c_time += chinese_number(hour) + "点";
        c_time += chinese_number(minute) + "分";
        // maybe not need srcond to show
        c_time += chinese_number(second) + "秒";

        if (type) {
                switch( type ) {
                        case 1: return c_year+c_month+c_time+c_week;
                        case 2: return c_year+c_month+c_time;
                        case 3: return c_month+c_time+c_week;
                        case 4: return c_month+c_time;
                        case 5: return year+"年"+(member_array(month, month_name) + 1)+
                                "月"+day+"日"+hour+"点"+minute+"分";
                        case 6: return (member_array(month, month_name) + 1)+
                                "月"+day+"日"+hour+"点"+minute+"分";
                        case 7: return year+"年"+(member_array(month, month_name) + 1)+
                                "月"+day+"日"+hour+"点"+minute+"分"+second+"秒";
						case 8: return hour+":"+minute+"-"+second;
						case 9: return hour+"";//返回整小时，作时间触发用。
						case 10:return year+"-"+(member_array(month, month_name) + 1)+"-"+day+"-"+hour;
						case 11:return year+"-"+(member_array(month, month_name) + 1)+"-"+day;
                        default: return c_year+c_month+c_time+c_week;
                        }
                }
        return c_year+c_month+c_time+c_week;
}

