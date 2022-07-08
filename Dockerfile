# Specify the parent image from which we build
FROM gcc:latest

LABEL org.opencontainers.image.source=ghcr.io/chloekkk/blackholeshell

# Set the working directory
WORKDIR /minishell

# Copy files from your host to your current working directory
COPY include ./include/
COPY src ./src/
COPY libft ./libft
COPY Makefile ./Makefile

# Build the application with cmake
RUN apt-get update -y && \
    apt-get autoremove -y

COPY ./entrypoint.sh /tmp/entrypoint.sh

RUN chmod +x /tmp/entrypoint.sh

ENTRYPOINT [ "/tmp/entrypoint.sh" ]

# Run the application
CMD ["./minishell"]
