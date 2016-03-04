#include <stdio.h>

/* import from consumer.java */
struct frame_data{
    char bssid[6];
    char res1[2];
    char sourceaddr[6];
    char res2[2];
    char destinationaddr[6];
    char res3[2];
    int  channel;
    int  length;
};

#define LENGTH_DECODER_SEPERATOR_START          3
#define LENGTH_DECODER_SEPERATOR_END            23
#define LENGTH_DECODER_SEPERATOR_DIFF           (LENGTH_DECODER_SEPERATOR_END - LENGTH_DECODER_SEPERATOR_START)
#define LENGTH_DECODER_MAX_SIZES                512
#define LENGTH_DECODER_SSID_TAG                 0x44b  //1099
#define LENGTH_DECODER_KEYPHRASE_TAG            0x4af  //1199
#define LENGTH_DECODER_DATA_MIN                 593
#define LENGTH_DECODER_MAX_UNSIGNED_BYTE        255
#define LENGTH_DECODER_DATA_MAX                 (LENGTH_DECODER_DATA_MIN + LENGTH_DECODER_MAX_UNSIGNED_BYTE)
#define LENGTH_DECODER_LEN_MIN                  28
#define LENGTH_DECODER_MAX_SEQUENCE_LEN         32
#define LENGTH_DECODER_LEN_MAX                  (LENGTH_DECODER_LEN_MIN + LENGTH_DECODER_MAX_SEQUENCE_LEN)

struct solver {
    char name[32];
    int solved;
};

void *solver(char *name)
{
    return NULL;
}

int solver_add(struct solver *sl, )
{
}

int solver_place(struct solver *sl, )
{
}

int solver_process(struct solver *sl, )
{
}

int analynzer_process(char *source, char *destination, int length)
{
#if 0
    printf("%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx\t%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx\t%d\n",
            source[0],
            source[1],
            source[2],
            source[3],
            source[4],
            source[5],
            destination[0],
            destination[1],
            destination[2],
            destination[3],
            destination[4],
            destination[5],
            length
            );
#endif

    /* found if has offset 20 */

    /* put the length to  */


    return 0;
}

/* input data */
int consumer_handle(char *frame)
{
        struct frame_data data;
        int ret;

        ret = sscanf(frame, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx\t%d\t%hhx:%hhx:%hhx:%hhx:%hhx:%hhx\t%hhx:%hhx:%hhx:%hhx:%hhx:%hhx\t%d\n",
                &data.bssid[0],
                &data.bssid[1],
                &data.bssid[2],
                &data.bssid[3],
                &data.bssid[4],
                &data.bssid[5],
                &data.channel,
                &data.sourceaddr[0],
                &data.sourceaddr[1],
                &data.sourceaddr[2],
                &data.sourceaddr[3],
                &data.sourceaddr[4],
                &data.sourceaddr[5],
                &data.destinationaddr[0],
                &data.destinationaddr[1],
                &data.destinationaddr[2],
                &data.destinationaddr[3],
                &data.destinationaddr[4],
                &data.destinationaddr[5],
                &data.length
                );

        if (ret != 20)
            return 0;

        return analynzer_process(data.sourceaddr, data.destinationaddr, data.length);
}

void consumer(FILE *stream)
{
    char buffer[128];
    int found = 0;

    while(fgets(buffer, sizeof(buffer), stream) != NULL) {
        if (consumer_handle(buffer)) {
            found = 1;
            break;
        }
    }

    printf("Scan %s\n", found ? "succeeded" : "failed");

    return;
}

int main(int argc, char **argv)
{
    FILE *stream;

    if (argc == 1)
        stream = stdin;
    else {
        stream = fopen(argv[1], "r");
        if (stream == NULL) {
            printf("open stream failed!\n");
            return -1;
        }
    }

    consumer(stream);

    return 0;
}

